#include<iostream>
#include<cstring>
#define INF 999999999
using namespace std;
int main()
{
    int e[1020][1020],dis[1020],book[1020];
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=INF;
        }
    }
    int t1,t2,t3;
    for(int i=1;i<=m;++i)
    {
        cin>>t1>>t2>>t3;
        e[t1][t2]=min(e[t1][t2],t3);
        e[t2][t1]=min(e[t2][t1],t3);
    }
    for(int i=1;i<=n;++i)
    {
        dis[i]=e[1][i];
    }
    memset(book,0,sizeof(book));
    book[1]=1;
    int u;
    for(int i=1;i<n;++i)
    {
        int MIN=INF;
        for(int j=1;j<=n;++j)
        {
            if(book[j]==0 && dis[j]<MIN)
            {
                MIN=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(int v=1;v<=n;++v)
        {
            if(e[u][v]<INF)
            {
                dis[v]=min(dis[v],dis[u]+e[u][v]);
            }
        }
    }
        cout<<dis[n]<<endl;
} 
