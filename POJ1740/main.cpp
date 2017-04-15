#include <iostream>
using namespace std;
int pos[110];
int main() {
    int n;
    while(~scanf("%d",&n)){
        memset(pos,0,sizeof(pos));
        if(n==0)
            break;
        int temp;
        for(int i=0;i<n;++i){
            scanf("%d",&temp);
            ++pos[temp];
        }
        int flag=0;
        for(int i=0;i<101;++i){
            if(pos[i]&1){
                flag=1;
                puts("1");
                break;
            }
        }
        if(!flag) puts("0");
    }
    return 0;
}