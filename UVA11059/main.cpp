#include <iostream>
using namespace std;
int a[20];
long long ans=0;
int main() {
    int n,t=1;
    while(~scanf("%d",&n)){
        ans=0;
        long long temp;
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<n;++i){
            temp=a[i];
            ans=max(ans,temp);
            for(int j=i+1;j<n;++j){
                temp*=a[j];
                ans=max(ans,temp);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n",t,ans);
        printf("\n");
        ++t;
    }
    return 0;
}