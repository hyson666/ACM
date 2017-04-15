//Graham Scan算法
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn= 1001;
const double pi = acos (-1.0);

struct node{
	double x,y;
}p[maxn],P[maxn];

//求取向量叉积。
double X(node A,node B,node C){	
	return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y); 
}

//求取长度。
double len(node A,node B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

//一定要定义sort的cmp操作。
bool cmp(node A,node B){
	double pp = X(p[0],A,B);
	if(pp>0) return true;
	if(pp<0) return false;
	return len(p[0],A)<len(p[0],B);
}

int main(){
	int v,n;
	double ans,l;
	scanf("%d",&v);
	for(int cas=0;cas<v;++cas){
		if(cas) printf("\n");
		scanf("%d%lf",&n,&l);
		for(int i=0;i<n;++i) 
		  scanf("%lf%lf",&p[i].x,&p[i].y);
		ans=2*pi*l;
		//先进行特判。
		if(n==1) printf("%.0lf\n",ans);
		else if(n==2) printf("%.0lf\n",ans+len(p[0],p[1]));
		else{
			//选取最左下的点。
			for(int i=1;i<n;++i){
				if(p[i].x<p[0].x) swap(p[i],p[0]);
				else if(p[i].x==p[0].x && p[i].y<p[0].y)
					swap(p[i],p[0]);
			}
			//建系后其他点按照极坐标编号。
			sort(p+1,p+n,cmp);
			P[0]=p[0];
			P[1]=p[1]; //容易证明这两个点一定在凸包当中。
			int top=1; //模拟栈的栈顶。
			for(int i=2;i<n;++i){
				//检测到左拐入栈，检测到右拐不断出栈。
				while(top>0 && X(P[top-1],P[top],p[i])<=0) top--;
				++top;
				P[top]=p[i];
			}
			//对加入到凸包的点进行求边长。
			for(int i=0;i<top;++i){
			  ans+=len(P[i],P[i+1]);
			}
			ans+=len(P[0],P[top]);
			printf("%.0f\n",ans);
		}
	}
}
