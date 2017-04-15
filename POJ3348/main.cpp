#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn= 10010;
const double pi = acos (-1.0);

struct node{
	double x,y;
}p[maxn],P[maxn];

double X(node A,node B,node C){	
	return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y); 
}

double len(node A,node B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

bool cmp(node &A,node &B){
	double pp = X(p[0],A,B);
	if(pp>0) return true;
	if(pp<0) return false;
	return len(p[0],A)<len(p[0],B);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lf%lf",&p[i].x,&p[i].y);
	if(n<=2) printf("0\n");
	else{
    	for(int i=1;i<n;++i){
			if(p[i].x<p[0].x) swap(p[i],p[0]);
			else if(p[i].x==p[0].x && p[i].y<p[0].y) swap(p[i],p[0]);
		}
		sort(p+1,p+n,cmp);
		P[0]=p[0];
		P[1]=p[1];
		int top=1;
		for(int i=2;i<n;++i){
			while(top>0 && X(P[top-1],P[top],p[i])<=0) top--;
			top++;
			P[top]=p[i];
		}
		int ans=0;
		for(int i=1;i<top;++i){
			ans+=fabs(X(P[0],P[i],P[i+1]))/2.0;
		}
		printf("%d\n",ans/50);
	}
}

