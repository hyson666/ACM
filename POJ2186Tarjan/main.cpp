#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 1e4+10;

vector<int> E[maxn],e[maxn];
stack<int> S;
int n,m,tag=1;  //tag用来记录当前编号到哪里。
int vis[maxn],dfn[maxn],low[maxn],tot,flag[maxn],out[maxn]; //flag[i]=点编号，用于缩图,w[maxn]用于记录缩图后的点权。
int found[maxn]; //用来在寻找答案时标记已经寻找过的flag

//利用tarjan进行染色处理。
void tarjan(int x){
	dfn[x]=low[x]=++tot;
	vis[x]=1;
	S.push(x);
	for(int i=0;i<E[x].size();++i){
		int v=E[x][i];
		if(!dfn[v]){
			tarjan(v);	
		    low[x]=min(low[v],low[x]);
		}
		//访问过了不在栈中的要继续维护,即是返回边。
		else if(vis[v])
		  low[x]=min(low[v],dfn[x]);
	}
	//弹到最后自己出来就已经确定好了一个连通分量。
	if(low[x]==dfn[x]){
		int cnt=0;
		while(1){
			int now = S.top();
			++cnt;
			vis[now]=0;
			S.pop();
			flag[now]=tag;
			if(now==x) break;
		}
		++tag;	//继续下一个点编号。
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int a,b;
	//建立两个单向图比较快，一个记录它崇拜谁，一个是谁崇拜它(处理后找最大点)。
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		E[a].push_back(b);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])
		  tarjan(i);
	}
	//Tarjan染色后进行统计操作。
	for(int i=1;i<=n;++i){
		for(int j=0;j<E[i].size();++j){
			int v=E[i][j];
			if(flag[i]!=flag[v])
				++out[flag[i]];
		}
	}
	int mark,num=0,ans=0;
	for(int i=1;i<tag;++i)
	  if(out[i]==0)
		++num,mark=i;
    //如果只有一个联通分量出度为0，这里面的所有牛肯定都被其他所有牛崇拜。
	if(num==1){
		for(int i=1;i<=n;++i)
			if(flag[i]==num)
			  ++ans;
	}
	else ans=0;
	printf("%d\n",ans);
}
