#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110;

vector<int> E[maxn];
stack<int> S;
int dfn[maxn], low[maxn], belong[maxn], cnt, tot,vis[maxn],n;
int in[maxn], out[maxn];

void tarjan(int x){
	dfn[x]=low[x]=++tot;
	S.push(x);
	vis[x]=1;
	for(int i=0;i<E[x].size();++i){
		int v=E[x][i];
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v])
		    low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		++cnt;
		while(1){
			int now = S.top();
			S.pop();
			vis[now]=0;
			belong[now]=cnt;
			if(now==x) break;
		}
	}
}

int main(){
	scanf("%d",&n);
	int temp;
	for(int i=1;i<=n;++i){
		while(scanf("%d",&temp) ,temp){
				E[i].push_back(temp);
		}
	}
	for(int i=1;i<=n;++i)
	  if(!dfn[i])
		tarjan(i);
	for(int i=1;i<=n;++i)
		for(int j=0;j<E[i].size();++j){
			int v=E[i][j];
			if(belong[i]!=belong[v]){
			  ++in[belong[v]];
			  ++out[belong[i]];
			}
		}
	int ans1=0,ans2=0;
	for(int i=1;i<=cnt;++i){
	  if(!in[i]) ++ans1;
	  if(!out[i]) ++ans2;
	}
	if(cnt==1){
		printf("1\n0\n");
	}
	else{
		printf("%d\n%d\n",ans1,max(ans1,ans2));
	}
	return 0;
}
