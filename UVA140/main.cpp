#include <iostream>
#include <cstring>
#define inf 99999999
using namespace std;
int s[100];
int mp[150][150];
int a[100];
char str[100];
int vis[150];
int MAX;
int ans=inf;
int n;
void dfs(int cur,int m){
    if(cur==n && m<ans){
        ans=m;
        memcpy(a,s,sizeof(s));
        return;
    }
    if(m>ans)
        return;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            s[cur]=i;
            vis[i]=1;
            for(int j=0;j<cur;++j)
                if(mp[i+65][j+65]) if(cur-j>m)  m=cur-j;
            dfs(cur+1,m);
            vis[i]=0;
        }
    }
    return;
}
int main(){
    int obj;
    int t=0;
    while(~scanf("%s",str)) {
        if(str[0]=='#')
            break;
        if(t++) printf("\n");
        memset(mp,0,sizeof(mp));
        memset(vis,false,sizeof(vis));
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        ans=inf,MAX=0;
        int num=(int)strlen(str);
        int k;
        for(k=0;k<num;++k){
            obj=str[k++];
            while(str[k]!=';' && k<num) {
                if (str[k] == '\0') break;
                if(str[k]>='A' && str[k] <='Z') {mp[obj][str[k]] = 1, mp[str[k]][obj] = 1, MAX = max(MAX, str[k] + 0);}
                ++k;
            }
        }
        n = MAX - 64;
        dfs(0, 0);
        for (int i = 0; i < n; ++i) {
            printf("%c ", 65 + a[i]);
        }
        printf("-> %d",ans);
    }
    return 0;
}
