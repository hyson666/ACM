#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int isp[40],n,A[20];
int vis[20];
int is_prime(int n)
{
    for(int i=2;i<=(int)sqrt(n);++i){
        if(n%i==0) return 0;
    }
    return 1;
}
void dfs(int cur)
{
    //注意是n,因为哨兵是枚举完之后一个数。
    if(cur==n && isp[A[n-1]+A[0]]){
        for(int i=0;i<cur;++i) {
            printf("%d", A[i]);
            printf("%s", i == n - 1 ?"\n":" ");
        }
    }
    else for(int i=1;i<=n;++i){
            if(!vis[i] && isp[A[cur-1]+i]) {
                A[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
}
int main() {
    int t=1;
    while(~scanf("%d",&n)) {
        if(t-1) printf("\n");
        memset(vis,0, sizeof(vis));
        for (int i = 2; i <= 2 * n; ++i) isp[i] = is_prime(i);
        A[0] = 1;
        vis[1] = 1;
        printf("Case %d:\n",t);
        dfs(1);
        ++t;
    }
    return 0;
}