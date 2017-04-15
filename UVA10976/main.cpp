#include <iostream>
using namespace std;
long long ansx[10010],ansy[10010];
int main() {
    long long k;
    while(~scanf("%lld",&k)){
        int cnt=0;
        for(long long y=k+1;y<=2*k;++y){
            long long check=(k*y)%(y-k);
                if(!check) {
                    ++cnt;
                    ansx[cnt] = k*y/(y-k);
                    ansy[cnt] = y;
                }
        }
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;++i){
            printf("1/%lld = 1/%lld + 1/%lld\n",k,ansx[i],ansy[i]);
        }
    }
    return 0;
}