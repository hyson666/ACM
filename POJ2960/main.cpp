#include <iostream>
#define MAXN 10010
using namespace std;
int s[105];
int SG[MAXN];
int n;
void getSG()
{
    for(int i=0;i<MAXN;++i){
        bool vis[MAXN]={false};
        for(int j=0;j<n;++j){
            if(i-s[j]>=0)
                vis[SG[i-s[j]]] = true;
        }
        int val;
        for(val=0;vis[val];++val);
        SG[i]=val;
    }
}
int main()
{
    while(~scanf("%d",&n)){
        if(n==0)
            break;
        memset(SG,-1,sizeof(SG));
        for(int i=0;i<n;++i)
            scanf("%d",&s[i]);
        getSG();
        int qnum;
        scanf("%d",&qnum);
        int ans;
        int temp;
        int k;
        while(qnum--){
            scanf("%d",&k);
            ans=0;
            while(k--) {
                scanf("%d", &temp);
                ans ^= SG[temp];
            }
            if(ans) cout<<"W";
            else cout<<"L";
        }
        putchar('\n');
    }
    return 0;
}
