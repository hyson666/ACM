#include <iostream>
#include <cmath>
#define INF 99999999999999
using namespace std;
int n,k;
double A[10010];
bool judge(double x)
{
    int num=0;
    for(int i=0;i<n;++i){
        num+=(int)(A[i]/x);
    }
    return num >= k;
}
int main()
{
    while(cin>>n>>k){
        double lb=0;
        double ub=INF;
        for(int i=0;i<n;++i)
            scanf("%lf",&A[i]);
        for(int i=0;i<100;++i){
            double mid=(lb+ub)/2;
            if(judge(mid))
                lb=mid;
            else
                ub=mid;
        }
        printf("%.2lf",floor(ub*100)/100);
    }
}
