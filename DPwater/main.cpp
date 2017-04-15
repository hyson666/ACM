#include <iostream>
#include <string>
#include <
using namespace std;
int dp[1001];
int a[1001];
int main() {
    int n,k;
    while(cin>>n>>k) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j)
                dp[i] = max(dp[i], dp[max(0, i - k)] + a[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
