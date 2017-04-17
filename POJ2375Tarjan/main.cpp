//POJ2375 存图，跑DFS，再建边。
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 500+10;
int G[maxn][maxn],gone[maxn][maxn],num[maxn][maxn];
int vis[maxn],dfn[maxn],low[maxn],tot,flag[maxn],tag,total,head[maxn];
int in[maxn],out[maxn],id;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
stack<int> S;
int m,n;

struct Edge{
	int to,next;
}E[maxn*maxn<<2];

void addEdge(int u,int v){
	E[id].to=v;
	E[id].next=head[u];
	head[u]=id++;
}

void tarjan(int u, int fa)
{
    int v;
    low[u] = dfn[u] = ++dfs_clock;
    S.push(u);
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(Instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        scc_cnt++;
        for(;;)
        {
            v = S.top();S.pop();
            Instack[v] = false;
            sccno[v] = scc_cnt;
            if(u == v) break;
        }
    }
}

struct Edge
{
    int from, to, next;
};
Edge edge[MAXM];
int point(int x, int y)
{
    return (x-1) * W + y;
}

void getMap()
{
    int move[4][2] = {0,1, 0,-1, 1,0, -1,0};
    for(int i = 1; i <= L; i++)// W L不要反了
    {
        for(int j = 1; j <= W; j++)
            scanf("%d", &Map[i][j]);
    }
    for(int i = 1; i <= L; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int x = i + move[k][0];
                int y = j + move[k][1];
                if(judge(x, y) && Map[x][y] <= Map[i][j])
                    addEdge(point(i, j), point(x, y));
            }
        }
    }
}

int main(){
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
    getMap();
	int tx,ty;
	for(int x=0;x<m;++x)
		for(int y=0;y<n;++y)
			for(int k=0;k<4;++k){
				tx=x+dx[k];
				ty=y+dy[k];
				if(G[x][y]>=G[tx][ty] && tx>=0 && ty>=0 && tx<m && ty<n){
					addEdge(num[x][y],num[tx][ty]);
				}
			}
	total=m*n;
	for(int i=0;i<total;++i)
	  if(!dfn[i])
		tarjan(i);
	for(int i=0;i<total;++i){
		for(int j=head[i];j!=-1;j=E[j].next){
			int v=E[i].to;
			if(flag[i]!=flag[v]){	
				in[flag[v]]++;
				out[flag[i]]++;
			}
		}
	}
	//统计出入度。
	int in_tot=0,out_tot=0;
	for(int i=1;i<=tag;++i){
		if(!in[i]) in_tot++;
		if(!out[i]) out_tot++;
	}
	if(tag==1)
	  printf("0\n");
	else
	  printf("%d",max(in_tot,out_tot));
}

