#include <iostream>
using namespace std;
int map[1010][1010];
int SG[1010];
int n,num,temp;
void getSG(int x)
{
    bool vis[1010]={false};
    for(int i=0;i<n;++i){
        if(map[x][i]){
            if(SG[i]==-1)
                getSG(i);
            vis[SG[i]]=true;
        }
    }
    int val;
    for(val=0;vis[val];++val);
    SG[x]=val;
}
int main()
{
    while(~scanf("%d",&n)) {
        memset(map, 0, sizeof(map));
        memset(SG, -1, sizeof(SG));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            while (num--) {
                scanf("%d", &temp);
                map[i][temp] = 1;
            }
        }
        for (int i = 0; i < n; ++i)
            if (SG[i] == -1)
                getSG(i);
        int q;
        int pos;
        while (~scanf("%d", &q)) {
            if(q==0)
                break;
            int ans = 0;
            while (q--) {
                scanf("%d", &pos);
                ans ^= SG[pos];
            }
            if (ans)
                puts("WIN");
            else
                puts("LOSE");
        }
    }
    return 0;
}
