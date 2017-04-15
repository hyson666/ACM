#include <iostream>
#include <cstdio>
int par[1010];
bool v[1010];
using namespace std;
struct node
{
    int xi;
    int yi;
}pos[1010];
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
        par[x]=y;
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
    int n;
    int d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;++i)
    {
        par[i]=i;
        v[i]=false;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>pos[i].xi>>pos[i].yi;
    }
    char type;
    int a,b;
    int temp1;
    int temp2;
    while(cin>>type)
    {
        if(type=='O')
        {
            scanf("%d",&a);
            if(v[a]==false)
                v[a]=true;
            for(int i=1;i<=n;++i)
            {
                if(v[i]==false)
                    continue;
                temp1=(pos[a].xi-pos[i].xi)*(pos[a].xi-pos[i].xi);
                temp2=(pos[a].yi-pos[i].yi)*(pos[a].yi-pos[i].yi);
                if(temp1+temp2<=d*d)
                {
                    unite(a,i);
                }
            }
        }
        if(type=='S')
        {
            scanf("%d%d",&a,&b);
            if(v[a]==true && v[b]==true && same(a,b))
                cout<<"SUCCESS"<<endl;
            else
                cout<<"FAIL"<<endl;
        }
    }
    return 0;
}