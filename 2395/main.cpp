#include <iostream>
#include <algorithm>
#define  ll long long
using namespace std;
#define maxn 100010
int n;
int par[maxn],rankk[maxn];
int find(int x)
{
    if(par[x]==x)
        return x;
    else
        return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    if(rankk[x]<rankk[y])
        par[x]=y;
    else
    {
        par[y]=x;
        if(rankk[x]==rankk[y])
            rankk[x]++;
    }

}
struct node
{
    int a,b;
    ll w;
    bool select;
}edge[maxn];
bool cmp(node a,node b)
{
    return a.w < b.w;
}
bool kruskal(node *edge,int n,int m)
{
    int k=0;
    int x,y;
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;++i){
        if(k==n-1) {
            return true;
        }
        if(edge[i].w==0)
            continue;
        x=find(edge[i].a);
        y=find(edge[i].b);
        if(x!=y){
            unite(x,y);
            k++;
            edge[i].select=true;
        }
    }
    return false;
}
int main() {
    int m,n;
    while(cin>>n>>m) {
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            rankk[i] = 0;
        }
        for(int i=1;i<=m;++i){
            cin>>edge[i].a>>edge[i].b>>edge[i].w;
        }
        kruskal(edge,n,m);
        ll ans=0;
        for(int i=1;i<=m;++i){
            if(edge[i].select){
                ans=max(ans,edge[i].w);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
