#include <iostream>
#include <cstdio>
using namespace std;
long long countt;
int par[300030];

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
    else
    {
        par[x]=y;
    }
}

bool same(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)
        return true;
    else
        return false;
}

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int type,a,b;
    int tempa,tempb;
    for(int i=1;i<=3*n;++i){
        par[i]=i;
    }
    while(k--){
        scanf("%d%d%d",&type,&a,&b);
        if(a>n || b>n){
            countt++;
            continue;
        }
        if(type==1){
            if(same(a,b+n) || same (a,b+2*n))
                countt++;
            else{
                unite(a,b);
                unite(a+n,b+n);
                unite(a+2*n,b+2*n);
            }
        }
        if(type==2){
            if(same(a,b) || same(a,b+2*n))
                countt++;
            else{
                unite(a,b+n);
                unite(a+n,b+2*n);
                unite(a+2*n,b);
            }
        }
    }
    cout<<countt<<endl;
    return 0;
}