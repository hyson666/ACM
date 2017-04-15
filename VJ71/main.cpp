#include <iostream>
#include <algorithm>
#define maxn 1000010
#define inf -999999999
using namespace std;
int num[maxn];
long long dp[2][maxn];
int main() {
    int m,n;
    while(cin>>m>>n)
    {
        for(int i=1;i<=n;++i){
            scanf("%d",&num[i]);
            dp[0][i]=num[i];
        }
        int countt=0;
        long long ans=inf;
        for(int i=1;i<=n;++i){
            countt+=num[i];
            dp[1][i]=countt;
            if(countt<0)
                countt=0;
        }
        long long maxx;
        for(int i=2;i<=m;++i){
            maxx=inf;
            dp[i%2][i]=dp[(i-1)%2][i-1]+num[i];
            for(int j=i+1;j<=n;++j){
                maxx=max(maxx,dp[(i-1)%2][j-1]);
                dp[i%2][j]=max(maxx+num[j],dp[i%2][j-1]);
            }
        }
        for(int i=1;i<=n;++i){
            ans=max(dp[m%2][i],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}