#include <iostream>
#include <algorithm>
using namespace std;
int pos[1010];
int main() {
    int q;
    cin>>q;
    while(q--){
        int n;
        scanf("%d",&n);
        pos[0]=0;
        for(int i=1;i<=n;++i) {
            scanf("%d", &pos[i]);
        }
        sort(pos,pos+n+1);
        int ans=0;
        for(int i=n;i>0;i-=2)
            ans^=(pos[i]-pos[i-1]-1);
        if(!ans) puts("Bob will win");
        else puts("Georgia will win");
    }
    return 0;
}