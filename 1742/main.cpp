#include <iostream>
using namespace std;
long long dp[101][100001];
int a[101];
int c[101];

int main() {
    int n,m;
    while(cin>>n>>m) {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        int count=1;
        for (int i = 1; i <= c[1]; ++i) {
            if(i*a[1]<=m) {
                dp[1][a[1] * i] = count;
                count++;
            }
            else
                break;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                 for(int k=1;k<=c[i] && k*a[j]<=j;++k){
                      dp[i][j]=max(dp[i][j],dp[i-1][j-k*a[j]]+k);
                     }
                 }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
