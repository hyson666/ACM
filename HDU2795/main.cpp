#include<iostream>
#include<algorithm>
#include<cstring>
int w,h,n;
using namespace std;
int A[200010];
struct segTree
{
    int l,r;
    int sum;
}tree[4*200010];

void init(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(tree[k].l==tree[k].r){
        tree[k].sum=w;
        return;
    }
    int mid=(l+r)/2;
    init(k<<1,l,mid);
    init(k<<1|1,mid+1,r);
    tree[k].sum=max(tree[k<<1].sum,tree[k<<1|1].sum);
}

int updata(int k,int board)
{
    int ret;
    if(tree[k].l==tree[k].r)
    {
        tree[k].sum-=board;
        return tree[k].l;
    }
    if(tree[2*k].sum>=board)
        ret=updata(k<<1,board);
    else
        ret=updata(k<<1|1,board);
    tree[k].sum=max(tree[k<<1].sum,tree[k<<1|1].sum);
    return ret;
}

int main()
{
    int board;
    while(cin>>h>>w>>n) {
        init(1, 1, min(h,n));
        while(n--){
            scanf("%d",&board);
            if(board<=tree[1].sum)
                printf("%d\n",updata(1,board));
            else
                puts("-1");
        }
    }
    return 0;
}
