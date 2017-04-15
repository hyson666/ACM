#include <iostream>
using namespace std;
int par[200020];
int rrank[200020];
int  find(int x)
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
    if(rrank[x]<rrank[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(rrank[x]==rrank[y])
            rrank[x]++;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=2*n;++i)
        {
            par[i]=i;
            rrank[i]=0;
        }
        char type;
        int a,b;
        getchar();
        while(m--)
        {
            scanf("%c%d%d%*c",&type,&a,&b);
            if(type=='A')
            {
                if(same(a,b) || same(a+n,b+n)){
                    printf("In the same gang.\n");
                }
                else if(same(a,b+n) || same(a+n,b)){
                    printf("In different gangs.\n");
                }
                else
                    printf("Not sure yet.\n");
            }
            if(type=='D')
            {
                unite(a,b+n);
                unite(a+n,b);
            }
        }
    }
    return 0;
}