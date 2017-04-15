#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int A[50005];

struct segTree {
    int l,r;
    int sum;
}tree[4*100010];

void build(int k, int l, int r) {
    tree[k].l=l;
    tree[k].r=r;
    if(tree[k].l==tree[k].r) {
        tree[k].sum=A[l];
        return;
    }
    int mid = (l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
//单点更新
void update(int k,int pos,int val) {
    if(tree[k].l==tree[k].r) {
        tree[k].sum+=val;
        return;
    }
    int mid=(tree[k].l+tree[k].r)>>1;
    if(pos<=mid) update(k<<1,pos,val);
    else update(k<<1|1,pos,val);
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}

int query(int k, int l, int r) {
    if(l<=tree[k].l && r>=tree[k].r) return tree[k].sum;
    int m=(tree[k].l+tree[k].r)>>1,ret=0;
    if(l<=m) ret+=query(k>>1, l, r);
    if(r>m) ret+=query(k>>1|1, l, r);
    return ret;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        for(int i =1; i<=n; i++) {
            scanf("%d", &A[i]);
        }
        build(1, 1, n);
        char op[10];
        int a, b;
        while(scanf("%s", op)) {
            if(op[0]=='E') break;
            scanf("%d%d", &a,&b);
            if(op[0]=='A') update(1, a, b);
            if(op[0]=='S') update(1, a, -b);
            if(op[0]=='Q') printf("%d\n" ,query(1, a, b));
        }
    }
    return 0;
}