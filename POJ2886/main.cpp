#include <iostream>
using namespace std;
char name[5000010][16];
int val[5000010];
int id;
int factor_table[5000010];
void init_factor_table(int n)
{
    fill(factor_table,factor_table+n+1,1);
    for(int i=2;i<=n;++i)
    {
        if(factor_table[i]==1)
        {
            for(int j=i; j<=n ;j+=i)
            {
                int k=0;
                for(int m=j;m%i==0;m/=i,++k);
                factor_table[j]*= k+1;
            }
        }
    }
}
struct segTree
{
    int l,r;
    int sum;
}tree[500010*3];
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
        pos-=tree[k<<1].sum;
        updata(k<<1|1,pos);
    }
    tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}
int main() {
    int num,k;
    while(cin>>num>>k){
        init_factor_table(num);
        build(1,1,num);
        int extimes=0;
        int temp=-1;
        for(int i=1;i<=num;++i){
            if(factor_table[i]>temp){
                extimes=i;
                temp=factor_table[i];
            }
        }
        for(int i=1;i<=num;++i){
            scanf("%s%d",name[i],&val[i]);
        }
        id=0;
        val[id]=0;
        for(int i=1;i<=extimes;++i){
            if(val[id]>0)
                k=((k+val[id]-2)%num+num)%num+1;
            else
                k=((k+val[id]-1)%num+num)%num+1;
            cout<<k<<endl;
            updata(1,k);
            cout<<name[id]<<endl;
            num--;
        }
        cout<<name[id]<<" "<<factor_table[extimes]<<endl;
    }
    return 0;
}
