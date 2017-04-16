#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
const int maxn=2e5+5;
vector<int> E[maxn];
stack<int> s;
int vis[maxn],ans=maxn,dfn[maxn],low[maxn],tot;

void tarjan(int x){
	low[x]=dfn[x]=++tot;
	s.push(x);
	vis[x]=1;
	for(int i=0;i<E[x].size();++i){	//要遍历自己所能达到的点（DFS）。
		int v=E[x][i];
		if(!dfn[v]){//从来没有访问，仍然是树枝边，继续遍历，用low维护low。
		  tarjan(v);
		  low[x]=min(low[v],low[x]); //维护的是当前tarjan点。
		}
		else if(vis[v])	//访问过了，就是返回边，用时间戳dfn维护low。
		  low[x]=min(low[v],dfn[x]);
	}
	if(low[x]==dfn[x]){
		int cnt=0;
		while(1){
			int now=s.top();
			++cnt;
			vis[now]=0;
			s.pop();
			if(now==x) break;
		}
		if(cnt>1) ans=min(ans,cnt);	//特判只有一点，永远不会返回自己。
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int temp;
	for(int i=1;i<=n;++i){
		scanf("%d",&temp);
		E[i].push_back(temp);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])
			tarjan(i);
	}
	printf("%d\n",ans);
}
