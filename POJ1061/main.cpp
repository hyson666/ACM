#include <iostream>
#define int64 long long
using namespace std;
int64 t;

int64 exgcd(int64 a,int64 b,int64 &x,int64 &y)
{
    int64 d=a;
    if(b!=0){
        d=exgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else{
        x=1;
        y=0;
    }
    return d;
}

int main() {
    int64 x1,y1,m,n,l;
    cin>>x1>>y1>>m>>n>>l;
    t=x1-y1;
    int64 a=n-m,b=l;
    int64 x,y;
    int64 m1=exgcd(a,b,x,y);
    if(t%m1!=0 || m==n)
        cout<<"Impossible"<<endl;
    else
    {
        b/=m1;
        x*=t/m1;
        x=(x%b+b)%b;
        cout<<x<<endl;
    }
    return 0;
}