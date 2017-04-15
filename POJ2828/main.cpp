#include <iostream>
using namespace std;
int que[2000010];
int pos[2000010],val[2000010];
int id;
struct segTree
{
    int l,r;
    int sum;
}tree[200010*3];
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(l==r){
        tree[k].sum=1;
        return;
    }
    int mid=(l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
void updata(int k,int pos)
{
    if(tree[k].l==tree[k].r)
    {
        id=tree[k].l;
        tree[k].sum--;
        return;
    }
    if(pos<=tree[k<<1].sum)
        updata(k<<1,pos);
    else {
        pos-=tree[k<<1].sum; //向左时直接插入,向右边的时候就要保证前面留有pos-1个空位,所以要减去前面的空位数.
        updata(k<<1|1,pos);
    }
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
int main() {
    int num;
    while(cin>>num){
        build(1,1,num);
        for(int i=1;i<=num;++i){
            scanf("%d%d",&pos[i],&val[i]);
        }
        for(int i=num;i>=1;--i){
            updata(1,pos[i]+1);
            que[id]=val[i];
        }
        printf("%d",que[1]);
        for(int i=2;i<=num;++i){
            printf(" %d",que[i]);
        }
        printf("\n");
    }
    return 0;
}