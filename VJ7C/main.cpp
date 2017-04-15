#include <iostream>
using namespace std;
char map[10][10];
int countt;
int ans=1;
int n,k;
int book[10][10];
int nextt[4][2]={{1,1},
                {1,-1},
                {-1,1},
                {-1,-1}};
bool judge(int x,int y)
{
    int tx=x+1;
    int ty=y;
    while(tx<=n){
        if(book[tx][ty]==1 && map[tx][ty]=='.')
            return false;
        tx++;
    }
    tx=x-1;
    ty=y;
    while(tx>=1 ){
        if(book[tx][ty]==1 && map[tx][ty]=='.')
            return false;
        tx--;
    }
    tx=x;
    ty=y+1;
    while(ty<=n){
        if(book[tx][ty]==1 && map[tx][ty]=='.')
            return false;
        ty++;
    }
    tx=x;
    ty=y-1;
    while(ty>=1){
        if(book[tx][ty]==1 && map[tx][ty]=='.')
            return false;
        ty--;
    }
    return true;
}
void dfs(int x,int y,int countt)
{
    if(countt==k){
        ans++;
        return;
    }
    int tx=x;
    int ty=y;
    for(int k=0;k<4;++k){
        tx=x+nextt[k][0];
        ty=y+nextt[k][1];
        if(tx<1 || ty<1 || tx>n || ty>n )
            continue;
        if(book[tx][ty]==0 && judge(tx,ty)){
            if(map[tx][ty]=='.') {
                book[tx][ty] = 1;
                dfs(tx, ty, countt + 1);
                book[tx][ty] = 0;
            }
            else {
                book[tx][ty] = 1;
                dfs(tx, ty, countt);
                book[tx][ty] = 0;
            }
        }
    }
}
int main() {
    while(cin>>n>>k)
    {
        memset(book,0,sizeof(book));
        ans=1;
        if(n==-1&&k==-1)
            break;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>map[i][j];
            }
        }
        book[1][3]=1;
        dfs(1,1,1);
        cout<<ans<<endl;
    }
    return 0;
}