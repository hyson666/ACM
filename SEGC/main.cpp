#include <iostream>
#include <algorithm>
#define MAXN 50010
using namespace std;
int stacks[50010];
int top;
struct segTree
{
    int l,r;
    int lsum,rsum,msum;
}tree[4*MAXN];
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].lsum=tree[k].rsum=tree[k].msum=r-l+1;
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}
void updata(int k,int pos,int val)
{
    if(tree[k].l==tree[k].r) {
        tree[k].lsum = tree[k].rsum = tree[k].msum = val;
        return;
    }
    int mid=(tree[k].l+tree[k].r)/2;
    if(pos<=mid)
        updata(k<<1,pos,val);
    else
        updata(k<<1|1,pos,val);
    tree[k].lsum=tree[k<<1].lsum;
    tree[k].rsum=tree[k<<1|1].rsum;
    if(tree[k<<1].lsum==tree[k<<1].r-tree[k<<1].l+1) tree[k].lsum+=tree[k<<1|1].lsum;   //修正根节点值
    if(tree[k<<1|1].lsum==tree[k<<1|1].r-tree[k<<1|1].l+1) tree[k].rsum+=tree[k<<1].rsum;
    tree[k].msum = max(max(tree[k<<1].msum,tree[k<<1|1].msum),tree[k<<1|1].lsum+tree[k<<1].lsum);
}
int query(int k,int pos)
{
    if(tree[k].r-tree[k].l+1==tree[k].msum || tree[k].msum==0 || tree[k].l==tree[k].r)
        return tree[k].msum;
    int mid=(tree[k].l+tree[k].r)/2;
    if(pos<=mid){
        if(tree[k<<1].r-tree[k<<1].rsum+1<=pos)
            return query(k<<1,pos)+query(k<<1|1,mid+1);
        else
            return query(k<<1,pos);
    }
    else{
        if(tree[k<<1|1].l+tree[k<<1|1].lsum-1>=pos)
            return query(k<<1|1,pos)+query(k<<1,mid);
        else
            return query(k<<1|1,pos);
    }
}
int main()
{
    int n,q;
    while(cin>>n>>q) {
        build(1, 1, n);
        char type[2];
        int a;
        while (q--) {
            scanf("%s", type);
            if (type[0] == 'D') {
                scanf("%d", &a);
                updata(1, a, 0);
                stacks[top++] = a;
            }
            if (type[0] == 'Q') {
                scanf("%d", &a);
                printf("%d\n", query(1, a));
            }
            if (type[0] == 'R') {
                if(top!=-1)
                    updata(1, stacks[--top], 1);
            }
        }
    }
}