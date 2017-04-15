#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 99999999
int d[105];
int n,m,x;
int money[105],rankk[105];
using namespace std;
struct EdgeNode
{
    int to;
    int w;
}e;
vector<EdgeNode> map[1010];
typedef pair<int,int> P;
typedef vector<EdgeNode>::iterator iter;
int dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+n+1,99999999);
    d[s]=money[s];
    que.push(P(0,s));
    for(int i=1;i<=n;++i)
    {
        if(i==s)
            continue;
        if (rankk[i] - rankk[s] <= m && rankk[i] >= rankk[s])
            d[i]=money[i];
    }
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first)
            continue;
        for(iter k=map[v].begin();k!=map[v].end();++k)
        {
            EdgeNode t=*k;
            if(d[t.to]>d[v]+t.w && abs(rankk[t.to]-rankk[s]<=m))
            {
                d[t.to]=d[v]+t.w;
                que.push(P(d[t.to],t.to));
            }
        }
    }
    return d[1];
}

int main()
{
    while(cin>>m>>n)
    {
        for(int i=1;i<=n;++i)
        {
            map[i].clear();
        }
        int cost;
        int from;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d%d",&money[i],&rankk[i],&x);
            while(x--) {
                scanf("%d%d",&from,&cost);
                e.to = i;
                e.w = cost;
                if(abs(rankk[i]-rankk[1]<=m))
                   map[from].push_back(e);
            }
        }
        int temp;
        int ans=money[1];
        for(int i=2;i<=n;++i)
        {
            temp=dijkstra(i);
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}