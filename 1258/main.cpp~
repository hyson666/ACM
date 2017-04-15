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
    return a.w<b.w;
}
void kruskal(node *edge,int n,int m)
{
    int k=0;
    int x,y;
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;++i){
        if(k==n-1)
            break;
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
}
int main() {
    int n;
    while(cin>>n) {
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            rankk[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                edge[(i - 1) * n + j].a = i;
                edge[(i - 1) * n + j].b = j;
                cin >> edge[(i - 1) * n + j].w;
            }
        }
        kruskal(edge, n, n * n);
        cout << sum << endl;
    }
    return 0;
}
