#include <iostream>
#define ll long long
using namespace std;
ll par[1000010];
ll d[1000010];
ll h[1000010];
ll find(ll x)
{
   if(par[x]==x)
       return x;
   else {
       ll t=par[x];
       par[x]=find(par[x]);
       d[x]+=d[t];
       return par[x];
   }
}

void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    else {
        d[x]+=h[y];
        h[y]+=h[x];
        par[x]=y;
        h[x]=0;
    }
}

int main() {
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        par[i]=i;
        d[i]=0;
        h[i]=1;
    }
    char c;
    int a,b;
    for(int i=0;i<n;++i)
    {
        cin>>c;
        if(c=='M')
        {
            cin>>a>>b;
            unite(a,b);
        }
        if(c=='C')
        {
            cin>>a;
            find(a);
            cout<<d[a]<<endl;
        }
    }
    return 0;
}
