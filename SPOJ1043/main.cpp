#include <iostream>
using namespace std;
int A[50010];
struct segTree
{
    int l,r;
    long long sum,lmax,rmax,mmax;
}tree[50010*4];
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(l==r){
        tree[k].lmax=tree[k].rmax=tree[k].sum=tree[k].mmax=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
    tree[k].lmax=max(tree[k<<1].lmax,tree[k<<1].sum+tree[k<<1|1].lmax);
    tree[k].rmax=max(tree[k<<1|1].rmax,tree[k<<1|1].sum+tree[k<<1].rmax);
    tree[k].mmax=max(tree[k<<1].mmax,tree[k<<1|1].mmax);
    tree[k].mmax=max(tree[k].mmax,tree[k<<1].rmax+tree[k<<1|1].lmax);
}
long long askr(int k,int l)
{
    if(tree[k].l==l)
        return tree[k].rmax;
    if(l>=tree[k<<1|1].l)
        return askr(k<<1|1,l);
    return max(tree[k<<1|1].rmax,tree[k<<1|1].sum+askr(k<<1,l));
}
long long askl(int k,int r)
{
    if(tree[k].r==r)
        return tree[k].lmax;
    if(r<=tree[k<<1].r)
        return askl(k<<1,r);
    return max(tree[k<<1].sum+askl(k<<1|1,r),tree[k<<1].lmax);
}
long long query(int k,int l,int r)
{
    if(l==tree[k].l && r==tree[k].r)   //这里的query求出来的是在区间中的最大和
        return tree[k].mmax;
    if(l>tree[k<<1].r)
        return query(k<<1|1,l,r);
    if(r<tree[k<<1|1].l)
        return query(k<<1,l,r);
    long long ret=max(query(k<<1,l,tree[k<<1].r),query(k<<1|1,tree[k<<1|1].l,r));   //这里求的是左右起的最大和,
                                                                                    //和build是一致的
    ret=max(ret,askl(k<<1|1,r)+askr(k<<1,l));
    return ret;
}
int main() {
    int num;
    while(cin>>num) {
        for (int i = 1; i <= num; ++i) {
            scanf("%d", &A[i]);
        }
        build(1, 1, num);
        int m;
        int ll, rr;
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &ll, &rr);
            printf("%lld\n", query(1, ll, rr));
        }
    }
    return 0;
}
