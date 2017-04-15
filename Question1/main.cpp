#include <iostream>
#include <queue>
using namespace std;
int par[10010];
int rankk[10010];
struct node
{
    int B,C,L;
    friend bool operator< (node n1,node n2)
    {
        return n1.C<n2.C;
    }
}nanja[10010];
priority_queue<node> que;
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
    if(x==y) return;
    if(rankk[x]<rankk[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rankk[x]==rankk[y]) rankk[x]++;
    }
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        par[i]=i;
        rankk[i]=0;
    }
    int i=0;
    while(cin>>nanja[i].B>>nanja[i].C>>nanja[i].L){
        unite(nanja[i].B,i);
        que.push(nanja[i]);
        ++i;
    }
    for(int j=0;j<n;++j){
        for(int k=j;k<n;++k){

        }
    }
    return 0;
}