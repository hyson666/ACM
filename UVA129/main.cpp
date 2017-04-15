#include <iostream>
#include <cstring>
using namespace std;
int s[100];
int cnt=0;
int n,l;
int dfs(int cur)
{
    if(cnt++ == n){
        for(int i=0;i<cur;++i){
            printf("%c",'A'+s[i]);
            if((i+1)%64==0 && i!=cur-1)
                printf("\n");
            else if((i+1)%4==0 && i!=cur-1)
                printf(" ");
        }
        printf("\n");
        printf("%d\n",cur);
        return 0;
    }
    for(int i=0;i<l;++i){
        int ok=1;
        s[cur]=i;
        for(int j=1;j<=(cur+1)/2;++j){  //即j<=(cur+1)/2,设置步长。
            int equal=1;
            for(int k=0;k<j;++k){
                if(s[cur-k]!=s[cur-k-j]){ equal=0;break; }
            }
            if(equal){ok=0;break;}
        }
        if(ok) if(!dfs(cur+1)) return 0;
    }
    return 1;
}
int main() {
    int t=0;
    while(~scanf("%d%d",&n,&l)){
        if(!n && !l) break;
        memset(s,0,sizeof(s));
        cnt=0;
        dfs(0);
    }
    return 0;
}