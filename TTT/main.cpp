#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 999999999999999
long d[100001];
long pre[100001];
using namespace std;
struct EdgeNode
{
    long to;
    long w;
}e;
vector<EdgeNode> map[100001];
typedef pair<long,long> P;
typedef vector<EdgeNode>::iterator iter;
int main()
{
    long n,m;
    while(cin>>n>>m)
    {
        memset(pre,0,sizeof(pre));
        long t1,t2,t3;
        for(int i=1;i<=n;++i)
        {
            map[i].clear();
        }
        int flag;
        for(int i=1;i<=m;++i)
        {
            flag=0;
            cin>>t1>>t2>>t3;
            e.to=t2;
            e.w=t3;
            vector<EdgeNode>::iterator iter=map[t1].begin();
            while(iter!=map[t1].end()){
                if(iter->to == t2) {
                    iter->w = min(t3, iter->w);
                    flag = 1;
                }
            }
            if(flag==0)
               map[t1].push_back(e);
            flag=0;
            iter=map[t2].begin();
            while(iter!=map[t2].end()){
                if(iter->to == t1) {
                    iter->w = min(t3, iter->w);
                    flag = 1;
                }
            }
            if(flag==0)
                map[t2].push_back(e);
        }
        priority_queue<P,vector<P>,greater<P> > que;
        fill(d,d+n+1,INF);
        pre[1]=0;
        d[1]=0;
        que.push(P(0,1));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            long v=p.second;
            if(d[v]<p.first)
                continue;
            for(iter k=map[v].begin();k!=map[v].end();++k)
            {
                flag=0;
                EdgeNode t=*k;
                if(d[t.to]>d[v]+t.w)
                {
                    d[t.to]=d[v]+t.w;
                    pre[t.to]=v;
                    que.push(P(d[t.to],t.to));
                }
            }
        }
        vector<long> path;
        if(d[n]!=INF)
        {
            for(;n!=0;n=pre[n])
                path.push_back(n);
            reverse(path.begin(),path.end());
            vector<long>::iterator iter=path.begin();
            while(iter!=path.end())
            {
                cout<<*iter<<" ";
                ++iter;
            }
            cout<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}
