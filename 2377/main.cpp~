#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010
int n;
int par[maxn],rankk[maxn];
int sum;
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
    int w;
    bool select;
}edge[maxn];
bool cmp(node a,node b)
{
    return a.w > b.w;
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
            sum+=edge[i].w;
            edge[i].select=true;
        }
    }
    return false;
}
int main() {
    int m,n;
    while(cin>>n>>m) {
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            rankk[i] = 0;
        }
        for(int i=1;i<=m;++i){
            cin>>edge[i].a>>edge[i].b>>edge[i].w;
        }
        if(kruskal(edge, n, m))
           cout << sum << endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
