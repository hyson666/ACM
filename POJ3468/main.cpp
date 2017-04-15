#include <iostream>
#define ll long long
using namespace std;
ll A[100010];
struct segTree
{
    int l,r;
    ll sum;
    ll mark;
}tree[4*100010];
void pushdown(int k)
{
    if(tree[k].mark != 0)
    {
        tree[k<<1].mark += tree[k].mark;
        tree[k<<1|1].mark += tree[k].mark;
        tree[k<<1].sum += (tree[k<<1].r-tree[k<<1].l+1)*tree[k].mark;
        tree[k<<1|1].sum += (tree[k<<1|1].r-tree[k<<1|1].l+1)*tree[k].mark;
        tree[k].mark=0;
    }
}
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(tree[k].l==tree[k].r){
        tree[k].sum=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
void updata(int k,int l,int r,ll val)
{
    if(l<=tree[k].l && tree[k].r<=r)
    {
        tree[k].mark+=val;
        tree[k].sum+=(tree[k].r-tree[k].l+1)*val;
        return;
    }
    pushdown(k);
    int mid=(tree[k].l+tree[k].r)/2;
    if(l<=mid)
        updata(k<<1,l,r,val);
    if(mid<r)
        updata(k<<1|1,l,r,val);
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
ll query(int k,int l,int r)
{
    if(l<=tree[k].l && tree[k].r<=r)
        return tree[k].sum;
    pushdown(k);
    int mid=(tree[k].l+tree[k].r)/2;
    ll ret=0;
    if(l<=mid)
        ret+=query(k<<1,l,r);
    if(r>mid)
        ret+=query(k<<1|1,l,r);
    return ret;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%lld",&A[i]);
    build(1,1,n);
    char type[2];
    int a,b;
    ll c;
    while(~scanf("%s",type))
    {
        if(type[0]=='Q'){
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(1,a,b));
        }
        else{
            scanf("%d%d%lld",&a,&b,&c);
            updata(1,a,b,c);
        }
    }
}