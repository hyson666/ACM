#include<iostream>
#define INF 99999999
using namespace std;
struct edge
{
    int from;
    int to;
    long long cost;
}e[10010];
int main()
{
    long long dis[10010];
    int n,m,w;
    int f;
    cin>>f;
    while(f--) {
        cin>>n>>m>>w;
        int t1,t2;
        long long t3;
        for(int i=1;i<=m;++i)
        {
            cin>>t1>>t2>>t3;
            e[i].from=t1;
            e[i].to=t2;
            e[i].cost=t3;
            e[i+m].from=t2;
            e[i+m].to=t1;
            e[i+m].cost=t3;

        }
        for(int i=2*m+1;i<=2*m+w;++i)
        {
            cin>>t1>>t2>>t3;
            e[i].from=t1;
            e[i].cost=-t3;
            e[i].to=t2;
        }
        memset(dis,0,sizeof(dis));
        int flag=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=2*m+w;++j){
                edge ee=e[j];
                if(dis[ee.to]>dis[ee.from]+ee.cost) {
                    dis[ee.to]=dis[ee.from]+ee.cost;
                    if (i == n) {
                        cout << "YES" << endl;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag==0)
            cout<<"NO"<<endl;
        }
    return 0;
}