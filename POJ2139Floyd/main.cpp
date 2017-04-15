#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 999999
int a[10010];
using namespace std;
int main()
{
    float e[301][301];
    int n,m;
    while(cin>>n>>m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j)
                    e[i][j] = 0;
                else
                    e[i][j] = INF;
            }
        }
        int t1;
        while (m--) {
            cin >> t1;
            for (int i = 1; i <= t1; ++i) {
                cin >> a[i];
            }
            for (int i = 1; i <= t1; ++i) {
                int first = a[i];
                for (int j = i + 1; j <= t1; ++j) {
                    int second = a[j];
                    e[first][second] = 1;
                    e[second][first] = 1;
                }
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    e[i][j] = e[i][j] < e[i][k] + e[k][j] ? e[i][j] : e[i][k] + e[k][j];
        int ans = INF;;
        for (int i = 1, j, sum; i <= n; ans = ans < sum ? ans : sum, i++)
            for (j = sum = 0; j <= n; j++)
                sum += e[i][j];
        cout << 100 * ans / (n - 1) << endl;
    }
    return 0;
}