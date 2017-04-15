#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
int d[1010][1010];
int n,m,x;
using namespace std;
struct EdgeNode
{
    int to;
    int w;
}e;
vector<EdgeNode> map[1010];
typedef pair<int,int> P;
typedef vector<EdgeNode>::iterator iter;
void dijkstra(int s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d[s],d[s]+n+1,99999999);
    d[s][s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[s][v]<p.first)
            continue;
        for(iter k=map[v].begin();k!=map[v].end();++k)
        {
            EdgeNode t=*k;
            if(d[s][t.to]>d[s][v]+t.w)
            {
                d[s][t.to]=d[s][v]+t.w;
                que.push(P(d[s][t.to],t.to));
            }
        }
    }
}

int main()
{
    while(cin>>n>>m>>x)
    {
        int t1,t2,t3;
        for(int i=1;i<=n;++i)
        {
            map[i].clear();
        }
        for(int i=1;i<=m;++i)
        {
            cin>>t1>>t2>>t3;
            e.to=t2;
            e.w=t3;
            map[t1].push_back(e);
        }
        dijkstra(x);
        int temp;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(i==x)
                continue;
            dijkstra(i);
            temp=d[i][x]+d[x][i];
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }
    return 0;
}


