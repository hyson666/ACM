#include <iostream>
using namespace std;
int a[1010];
int main() {
    int n;
    while(~scanf("%d",&n)){
        if(n==0)
            break;
        int res=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            res^=a[i];
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(a[i]>(res^a[i]))
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}