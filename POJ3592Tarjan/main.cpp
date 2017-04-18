#include <iostream>
#include <stack>
using namespace std;

const int maxn = 2500+10;
int id,n,m,G[45][45],head[maxn],transnum[maxn],iid,hhead[maxn];
int dfn[maxn],low[maxn],flag[maxn],tot,vis[maxn],tag,w[maxn],dp[maxn];
int dx[2]={1,0},dy[2]={0,1};
stack<int> S;

struct Edge{
    int from,next,to;
}E[maxn<<2],e[maxn<<2];

void init(){
    id=0,tag=0,tot=0,iid=0;
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    memset(head,-1,sizeof head);
    memset(hhead,-1,sizeof hhead);
    memset(vis,0,sizeof vis);
    memset(flag,0,sizeof flag);
    memset(transnum,0,sizeof transnum);
    memset(w,0,sizeof w);
    memset(G,0,sizeof G);
}

int point(int x,int y){
    return x*m + y;
}

bool judge(int x,int y){
    return x>=0 && x<n && y>=0 && y<m && G[x][y]!=-1;
}

void addEdge(int u,int v){
    E[id].from=u;
    E[id].to=v;
    E[id].next=head[u];
    head[u]=id++;
}

void addEdge2(int u,int v){
    e[iid].from=u;
    e[iid].to=v;
    e[iid].next=hhead[u];
    hhead[u]=iid++;
}

int askw(int num){
    int y = num % m ;
    int x = (num-y)/m ;
    if(G[x][y]>0)
        return G[x][y];
    else
        return 0;
}

void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    vis[x] = 1;
    S.push(x);
    for(int i=head[x];i!=-1;i=E[i].next){
        int v=E[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x]){
        ++tag;
        while(1){
            int now=S.top();
            S.pop();
            vis[now]=0;
            flag[now]=tag;
            w[tag] += askw(now);
            if(now == x) break;
        }
    }
}

//记忆化DFS跑最短路用的
int dfs(int x){
    if(dp[x]>-1)
        return dp[x];
    dp[x]=0;
    for(int i=hhead[x];i!=-1;i=e[i].next)
        dp[x]=max(dp[x],dfs(e[i].to));
    dp[x]+=w[x];
    return dp[x];
}

int main(){
    int v;
    scanf("%d",&v);
    for(int cas=0;cas<v;++cas){
        init();
        scanf("%d%d",&n,&m);
        char temp[maxn];
        int num,transcnt=0;
        for(int i=0;i<n;++i){
            scanf("%s\n",temp);
            for(int j=0;j<m;++j){
                if(temp[j]=='#')
                    G[i][j]=-1;
                else if(temp[j] == '*'){
                    transcnt++;
                    G[i][j]=0;
                    transnum[transcnt]=point(i,j);
                }
                else{
                    num=temp[j]-'0';
                    G[i][j]=num;
                }
            }
        }
        //建立图内连通。
        for(int x=0;x<n;++x)
            for(int y=0;y<m;++y) {
                if(G[x][y]!=-1) {
                    for (int k = 0; k < 2; ++k) {
                        int tx = x + dx[k], ty = y + dy[k];
                        if (judge(tx, ty) && G[tx][ty] != -1) {
                            addEdge(point(x, y), point(tx, ty));
                        }
                    }
                }
            }
        //建立传送门。
        int u,r,pnum;
        for(int i=1;i<=transcnt;++i){
            scanf("%d%d",&u,&r);
            pnum = point(u,r);
            addEdge(transnum[i],pnum);
        }
        int total = maxn;
        for(int i=0;i<maxn;++i)
            if(!dfn[i])
                tarjan(i);
        //建立缩点图跑最长路用。
        for(int i=0;i<id;++i){
            u = flag[E[i].from],r=flag[E[i].to];
            if(u!=r)
                addEdge2(u,r);
        }
        //记忆化DFS跑DAG最短路（DP）。
        for(int i=1;i<=tag;++i)
            dp[i]=-1;
        int ans = dfs(flag[0]);
        printf("%d\n", ans);
    }
}

