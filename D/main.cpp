#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100];
bool HASH[100];
bool HASH1[100000];
bool HASH2[100000];
int m[100000],q[100000];
int main() {
    int v;
    while(~scanf("%d",&v)){
        memset(HASH1,false,sizeof(HASH1));
        memset(HASH2,false,sizeof(HASH2));
        memset(HASH,false,sizeof(HASH));
        int n=0;
        int tt;
        while(v--){
            scanf("%d",&tt);
            if(!HASH[tt]){
                ++n;
                a[n]=tt;
                HASH[tt]=true;
            }
        }
        int temp;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    HASH1[100*a[i]+10*a[j]+a[k]] = true;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    for (int s = 1; s <= n; ++s) {
                        HASH2[1000*a[i]+100*a[j]+10*a[k]+a[s]] = true;
                    }
                }
            }
        }
        int mnum = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    m[mnum++] = 100*a[i]+10*a[j]+a[k];
                }
            }
        }
        int nnum = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                q[nnum++] = 10*a[i]+a[j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= mnum; ++i) {
            for (int j = 1; j <= nnum; ++j) {
                if (HASH1[(q[j] % 10) * m[i]] && HASH1[(q[j] / 10) * m[i]] && HASH2[m[i] * q[j]])
                    ++ans;
            }
        }
        cout << ans << endl;
    }
}