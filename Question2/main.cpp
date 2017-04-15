#include<bits/stdc++.h>
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
        tree[k].sum=A[l];
        return;
    }
    int mid=(l+r)/2;
    init(k<<1,l,mid);
    init(k<<1|1,mid+1,r);
	if(tree[k<<1].sum>=0 && tree[k<<1|1].sum>=0)
	  tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
	else if(tree[k<<1].sum>0 && tree[k<<1|1].sum<0)
	  tree[k].sum=tree[k<<1].sum;
	else
	  tree[k].sum=tree[k<<1|1].sum;
    tree[k].sum=max(tree[k<<1].sum,tree[k<<1|1].sum);
}

void updata(int k,int pos,int val)
{
    if(tree[k].l==tree[k].r)
    {
        tree[k].sum=val;
        return;
    }
    int mid=(tree[k].l+tree[k].r)/2;
    if(pos<=mid)
        updata(k<<1,pos,val);
    else
        updata(k<<1|1,pos,val);	
	if(tree[k<<1].sum>=0 && tree[k<<1|1].sum>=0)
	  tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
	else if(tree[k<<1].sum>0 && tree[k<<1|1].sum<0)
	  tree[k].sum=tree[k<<1].sum;
	else
	  tree[k].sum=tree[k<<1|1].sum;
}

int query(int k,int l,int r)
{
    if(l<=tree[k].l && r>=tree[k].r)
        return tree[k].sum;
    int m=(tree[k].l+tree[k].r)/2,ret=0;
    if(l<=m)
        ret+=query(k<<1,l,r);
    if(r>m)
        ret+=query(k<<1|1,l,r);
    return ret;
}

int main()
{
    int n,num;
    while(cin>>num) {
        for (int k = 1; k <= num; ++k)
            scanf("%d", &A[k]);
        init(1, 1, num);
        int type;
        int a, b;
		cin>>n;
        while (n--) {
            scanf("%d",&type);
            scanf("%d%d", &a, &b);
            if (type == 1) {
                if (a > b)
                    swap(a, b);
                printf("%d\n", query(1, a, b));
            }
            else if (type ==0) {
                A[a] = b;
                updata(1, a, A[a]);
            }
        }
    }
    return 0;
}
