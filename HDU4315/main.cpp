//阶梯博弈变形。
#include <iostream>
#include <algorithm>
int pos[1010];
using namespace std;
int main() {
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;++i){
            scanf("%d",&pos[i]);
        }
        sort(pos,pos+n);
        int ans=0;
        if(n&1) ans = pos[0] -(k==2);
        for(int i=(n&1);i<n-1;i+=2){
            ans^=(pos[i+1]-pos[i]-1);
        }
        if(ans || k==1) puts("Alice");
        else puts("Bob");
    }
    return 0;
}