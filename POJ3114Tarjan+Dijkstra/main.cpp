#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 500+10;
const int inf = INT_MAX;
int n,m,id,head[maxn],flag[maxn],tot,tag,dfn[maxn],low[maxn],vis[maxn],gone[maxn];
int iid,hhead[maxn];
stack<int> S;

struct Edge{
    int from,to,next,h;
}E[maxn*maxn],e[maxn*maxn];

struct Node{
    int dis,id;
    friend  bool operator < (Node A,Node B){
        return A.dis > B.dis;
    }
}ans[maxn];

priority_queue<Node> que;

void init(){
    id=tag=tot=iid=0;
    memset(head,-1,sizeof head);
    memset(hhead,-1,sizeof hhead);
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
}

void addEdge(int u,int v,int h){
    E[id].from = u;
    E[id].to = v;
    E[id].next = head[u];
    E[id].h = h;
    head[u]=id++;
}

void addEdge2(int u,int v,int h){
    e[iid].from = u;
    e[iid].to = v;
    e[iid].next = hhead[u];
    e[iid].h = h;
    hhead[u]=iid++;
}

void tarjan(int x){
    dfn[x]=low[x]=++tot;
    S.push(x);
    vis[x]=1;
    for(int i=head[x];i!=-1;i=E[i].next){
        int v=E[i].to;
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){
        ++tag;
        while(1){
            int now=S.top();
            S.pop();
            vis[now]=0;
            flag[now]=tag;
            if(now==x) break;
        }
    }
}

//书本上没有加gone标记的模板会WA,故换此模板。
void Dijkstra(int x){
    while(!que.empty()) que.pop();
    //记得清空访问标记。
    memset(gone,0,sizeof gone);
    for(int i=1;i<=tag;++i){
        ans[i].dis=inf;
        ans[i].id=i;
    }
    ans[x].dis = 0;
    que.push(ans[x]);
    while(!que.empty()){
        Node u = que.top();
        que.pop();
        //若当前点u松弛过了直接continue,不加这个会WA,同时未访问就标记。
        if(gone[u.id]) continue;
        gone[u.id] = 1;
        for(int i=hhead[u.id];i!=-1;i=e[i].next){
            int v=e[i].to;
            //这里的工作就是通过u可以用的边松弛它到其他各个点的距离。
            ans[v].dis = min(ans[v].dis,u.dis+e[i].h);
            //松弛完之后加入队列。
            que.push(ans[v]);
        }
    }
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        init();
        int u,v,h;
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&u,&v,&h);
            addEdge(u,v,h);
        }
        for(int i=1;i<=n;++i)
            if(!dfn[i])
                tarjan(i);
        for(int i=0;i<id;++i){
            u=flag[E[i].from],v=flag[E[i].to];
            if(u!=v){
                addEdge2(u,v,E[i].h);
            }
        }
        int k;
        scanf("%d",&k);
        int o,d;
        for(int i=0;i<k;++i){
            scanf("%d%d",&o,&d);
            if(flag[o]==flag[d])
                printf("0\n");
            else{
                Dijkstra(flag[o]);
                if(ans[flag[d]].dis!=inf)
                    printf("%d\n",ans[flag[d]].dis);
                else
                    printf("Nao e possivel entregar a carta\n");
            }
        }
        printf("\n");
    }
}

