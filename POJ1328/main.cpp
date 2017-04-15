#include <iostream>
#include <cmath>
#include <algorithm>
int n;
double d;
using namespace std;
struct node
{
    double begin;
    double end;
}radar[100010];
bool cmp(node a,node b)
{
    return a.begin<b.begin;
}
int solve()
{
    double x,y;
    double temp;
    int good=0;
    for(int i=0;i<n;++i){
            cin>>x>>y;
            if(y>d)
            {
                good=1;
            }
            temp=sqrt(d*d-y*y);
            radar[i].begin=x-temp;
            radar[i].end=x+temp;
        }
    if(good==1)
        return -1;
    if(d<=0)
        return -1;
    sort(radar,radar+n,cmp);
    int ans=0;
    double end=-99999999;
    for(int i=0;i<n;++i){
        if(radar[i].end<end){
            end=radar[i].end;
        }
        else if(radar[i].begin>end){
            ans++;
            end=radar[i].end;
        }
    }
    return ans;
}
int main() {
    int count=1;
    while(scanf("%d%lf",&n,&d)) {
        if (n == 0 && d == 0)
            break;
        cout <<"Case "<<count<<": " << solve() << endl;
        count++;
    }
    return 0;
}