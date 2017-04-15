#include <iostream>
#include <cmath>
#define M_PI 3.1415926535
using namespace std;
const int MAX_N=500000;
int L[100010];
int S[MAX_N],A[MAX_N];
int N,C;
double vx[MAX_N],vy[MAX_N];
double ang[MAX_N];
double pre[MAX_N];
void init(int k,int l,int r)
{
    ang[k]=vx[k]=0.0;
    if(r-l==1)
        vy[k]=L[l];
    else{
        int chl=k*2+1,chr=k*2+2;
        init(chl,l,(l+r)/2);
        init(chr,(l+r)/2,r);
        vy[k]=vy[chl]+vy[chr];
    }
}
void change(int s,double a,int v,int l,int r)
{
    if(s<=l) return;
    else if(s<r)
    {
        int chl=v*2+1,chr=v*2+2;
        int m=(l+r)/2;
        change(s,a,chl,l,m);
        change(s,a,chr,m,r);
        if(s<=m) ang[v]+=a;
        double s=sin(ang[v]),c=cos(ang[v]);
        vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
        vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
    }
}
void solve()
{
    init(0,0,N);
    for(int i=1;i<N;++i)
        pre[i]=M_PI;
    for(int i=0;i<C;++i){
        int s=S[i];
        double a=A[i]/360.0*2*M_PI;
        change(s,a-pre[s],0,0,N);
        pre[s]=a;
        printf("%.2lf %.2lf\n",vx[0],vy[0]);
    }
}
int main() {
    while(cin>>N>>C) {
        memset(vx,0,sizeof(vx));
        memset(vy,0,sizeof(vy));
        for (int i = 0; i < N; ++i)
            scanf("%d", &L[i]);
        for (int i = 0; i < C; ++i)
            scanf("%d%d", &S[i], &A[i]);
        solve();
        cout<<endl;
    }
}