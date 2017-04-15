#include <iostream>
#define MAXN 65540<<1
using namespace std;
char type[2];
bool HASH[MAXN];
struct segTree
{
    int l,r;
    int cover;
    int XOR;
}tree[4*MAXN];
void funXor(int k)
{
    if(tree[k].cover != -1) tree[k].cover ^= 1;
    else tree[k].XOR ^= 1;
}
void pushdown(int k)
{
    //若存在覆盖标记,则之前的异或标记是失效的,直接覆盖掉。
    if(tree[k].cover != -1){
        tree[k<<1].cover=tree[k<<1|1].cover = tree[k].cover;
        tree[k<<1].XOR=tree[k<<1|1].XOR=0;
        tree[k].cover=-1;
    }
    //如果只存在异或标记的话,就进行按位异或操作。
    if(tree[k].XOR){
        funXor(k<<1);
        funXor(k<<1|1);
        tree[k].XOR=0;
    }
}
void build(int k,int l,int r)
{
    tree[k].l=l;
    tree[k].r=r;
    if(l==r)
        return;
    int mid = (l+r)/2;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}
void updata(int k,int l,int r)
{
    if(l<=tree[k].l && tree[k].r<=r) {
        if (type[0] == 'U') {      //如果是合并操作则原来的异或标记就要清空。
            tree[k].cover = 1;
            tree[k].XOR = 0;
        }
        else if (type[0] == 'D') {
            tree[k].cover = 0;
            tree[k].XOR = 0;
        }
        else if (type[0] == 'C' || type[0] == 'S') {
            funXor(k);
        }
        return;
    }
    pushdown(k);
    int m=(tree[k].l+tree[k].r)>>1;
    if(l<=m) updata(k<<1,l,r);
    else if(type[0]=='I' || type[0]=='C') {
        tree[k<<1].XOR = tree[k<<1].cover = 0;
    }
    if(m<r) updata(k<<1|1,l,r);
    else if(type[0]=='I' || type[0]=='C'){
        tree[k<<1|1].XOR = tree[k<<1|1].cover = 0;
    }

}
void query(int k,int l,int r)
{
    if(tree[k].cover == 1){
        for(int i=tree[k].l ; i<=tree[k].r ; ++i){
            HASH[i]=true;
        }
        return;
    }
    else if(tree[k].cover==0) return;
    if(tree[k].l == tree[k].r) return;
    pushdown(k);
    int mid = (tree[k].l+tree[k].r)/2;
    if(l<=mid)  query(k<<1,l,r);
    if(r>mid)   query(k<<1|1,l,r);
}
int main() {
    int a,b;
    char l,r;
    build(1,1,MAXN);
    bool judge0=false;
    while(~scanf("%s %c%d,%d%c",type,&l,&a,&b,&r)){
        if(type[0]=='G')
            break;
        a<<=1,b<<=1;  //倍增化,把开闭的区间全部转化为闭区间来处理。
        if(l=='(') a++;
        if(r==')') b--;
        if(a==0 && l=='[')
            judge0=true;
        updata(1,a,b);
    }
    query(1,1,MAXN);
    int s=-1,e;
    int flag=0;
    for(int i=1;i<=MAXN;++i){
        if(HASH[i]==1){
            if(s == -1){
                s=i;
            }
            e=i;
        }
        else{
            if(s!=-1){
                flag=1;
                printf("%c%d,%d%c ",s%2==0 || s==1&&judge0?'[':'(',s>>1,(e+1)>>1,e%2==0?']':')');
                s=-1;
            }
        }
    }
    if(!flag) printf("empty set\n");
    return 0;
}