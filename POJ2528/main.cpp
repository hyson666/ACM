#include <iostream>
#include <algorithm>
#define ll long long
#define maxn 200010
using namespace std;
int color;
ll l[maxn],r[maxn];
ll t[maxn<<3];
ll x[maxn<<3];
bool Hash[maxn];
ll ans;
struct segTree
{
    int l,r;
    int mark;
}tree[maxn<<4];
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    tree[k].mark=0;
    int mid=(l+r)/2;
    if(tree[k].l==tree[k].r)
        return;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}
void pushdown(int k)
{
    if(tree[k].mark!=0)
    {
        tree[k<<1].mark=tree[k<<1|1].mark=tree[k].mark;
        tree[k].mark=0;
    }
}
void updata(int k,int l,int r)
{
    if(l<=tree[k].l && tree[k].r<=r)
    {
        tree[k].mark=color;
        return;
    }
    pushdown(k);
    ll mid=(tree[k].l+tree[k].r)/2;
    if(l<=mid) updata(k<<1,l,r);
    if(mid<r) updata(k<<1|1,l,r);
}
void query(int k,int l,int r)
{
    if(tree[k].mark != 0){
        if(!Hash[tree[k].mark]) {
            ans++;
            Hash[tree[k].mark] = true;
            return;
        }
    }
    pushdown(k);
    if(tree[k].l==tree[k].r)
        return;
    ll mid=(tree[k].l+tree[k].r)/2;
    if(l<=mid)
        query(k<<1,l,r);
    if(r>mid)
        query(k<<1|1,l,r);
}
int binsearch(int l,int r,int key)
{
    while(l<=r){
        int mid=(l+r)/2;
        if(key==x[mid])
            return mid;
        else if(key>x[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}
int main() {
    int v;
    cin>>v;
    while(v--)
    {
        int q;
        cin>>q;
        ll pos=1;
        for(int i=0;i<q;++i){
            scanf("%lld%lld",&l[i],&r[i]);
            t[pos++]=l[i];
            t[pos++]=r[i];
        }
        sort(t,t+pos);
        ll temp=1;
        for(ll i=1;i<pos;++i){
            if(t[i]!=t[i+1])    //如果相等则pos指针一直往后,不再执行赋值直到正常,从而去除重复。
                t[temp++]=t[i];
        }
        x[1]=t[1];
        int k=2;
        //接下来对距离大于1的点进行处理。
        for(ll i=2;i<temp;++i){
            if(t[i]-t[i-1]!=1)
                x[k++] = t[i-1] + 1;
            x[k++]=t[i];
        }
        int le,ri;
        color=1;
        build(1,1,k-1);
        for(int i=0;i<q;++i){
            le = binsearch(1,k-1,l[i]);
            ri = binsearch(1,k-1,r[i]);
            updata(1,le,ri);
            color++;
        }
        ans=0;
        memset(Hash,false,sizeof(Hash));
        query(1,1,k-1);
        printf("%lld\n",ans);
    }
    return 0;
}