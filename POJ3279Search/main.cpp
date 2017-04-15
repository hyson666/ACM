#include <iostream>
using namespace std;
const int INF=1<<15;
int m,n;
int ans=INF;
int map[18][18];
int state[18][18];
int temp[18][18];
int rec[18][18];
int dx[5]={1,0,-1,0,0},dy[5]={0,1,0,-1,0};
int flag;
void flip(int x,int y)
{
    temp[x][y]=1;
    int nx,ny;
    for(int i=0;i<5;++i){
        nx=x+dx[i],ny=y+dy[i];
        state[nx][ny]=!state[nx][ny];
    }
}
bool check()
{
    for(int i=1;i<=n;++i){
        if(state[m][i]==1)
            return false;
    }
    return true;
}
void solve(int st)
{
    memcpy(state,map,sizeof(map));
    memset(temp,0,sizeof(temp));
    int cnt=0;
    for(int i=0;i<m;++i)
        if((st>>i)&1){
            flip(1,i+1);
            ++cnt;
        }
    for(int i=2;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(state[i-1][j]==1){
                flip(i,j);
                ++cnt;
            }
        }
    }
    if(check()){
        flag=1;
        memcpy(rec,temp,sizeof(temp));
        ans=cnt;
    }
}
int main(){
    while(~scanf("%d%d",&m,&n)){
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&map[i][j]);
        int end=1<<n;
        for(int st=0;st<end;++st) {
            solve(st);
            if (flag == 1)
                break;
        }
        if(ans!=INF){
            for(int i=1;i<=m;++i) {
                for (int j = 1; j <= n; ++j) {
                    printf("%d ", rec[i][j]);
                }
                putchar('\n');
            }
        }
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}