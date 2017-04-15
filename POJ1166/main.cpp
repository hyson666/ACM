#include<iostream>
#include<algorithm>
using namespace std;
int A[50010];
struct segTree
{
	int l,r;
	int sum;
}tree[4*50010];

void init(int k,int l,int r)
{
	tree[k].l=l;
	tree[k].r=r;
	if(l==r){
		tree[k].sum=A[l];
		return;
	}
	int mid=(l+r)/2;
	init(k<<1,l,mid);
	init(k<<1|1,mid+1,r);
	tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}

void updata(int k,int pos,int val)
{
	if(tree[k].l==tree[k].r)
	{
		tree[k].sum=val;
		return;
	}
	int mid=(tree[k].l+tree[k].r)/2;
	if(pos<mid)
	  updata(k<<1,pos,val);
	else
	  updata(k<<1|1,pos,val);
	tree[k].sum=tree[k<<1].sum+tree[k<<1|1].sum;
}

int query(int k,int l,int r)
{
	if(l<=tree[k].l && r>=tree[k].r)
		return tree[k].sum;
	int m=(tree[k].l+tree[k].r)/2,ret=0;
	if(l<=m)
	  ret+=query(k<<1,l,m);
	if(r>m)
	  ret+=query(k<<1|1,m,r);
	return ret;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int num;
		cin>>num;
		for(int i=1;i<=num;++i)
		  scanf("%d",&A[i]);
		init(1,1,num);
		string s;
		int a,b;
		while(cin>>s)
		{
			if(s=="End")
			  break;
			scanf("%d%d",&a,&b);
			if(s=="Query"){
				if(a>b)
				  swap(a,b);
			    printf("%d", query(1,a,b));
			}
			if(s=="Sub"){
				A[a]-=b;
				updata(1,a,A[a]);
			}
			if(s=="Add"){
				A[a]+=b;
				updata(1,a,A[a]);
			}
		}
	}
	return 0;
}
