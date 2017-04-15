#include <iostream>
#include <queue>
using namespace std;
int l,r,c;
char m[35][35][35];
int ans;
int startl,startx,starty;
int endlevel,endx,endy;
bool visited[35][35][35];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node
{
    int l,x,y,step;
}pos;
bool bfs()
{
    queue<node> que;
    pos.l=startl,pos.x=startx,pos.y=starty,pos.step=0;
    que.push(pos);
    visited[startl][startx][starty]=true;
    while(que.size())
    {
        node p=que.front();
        que.pop();
        if(p.l==endlevel && p.x==endx && p.y==endy){
            ans=p.step;
            return true;
        }
        for(int i=0;i<=5;++i){
            int nx,ny,nl;
            if(i<=3) {
                nx = p.x + dx[i];
                ny = p.y + dy[i];
                nl = p.l;
            }
            if(i==4) {
                nx = p.x;
                ny = p.y;
                nl = p.l+1;
            }
            if(i==5){
                nx = p.x;
                ny = p.y;
                nl = p.l-1;
            }
            if(nx>=1 && ny>=1 && !visited[nl][nx][ny] && m[nl][nx][ny]=='.' && nx<=r && ny<=c && nl<=l && nl>=1){
                node q;
                q.x=nx,q.y=ny,q.step=p.step+1,q.l=nl;
                visited[nl][nx][ny]=true;
                que.push(q);
            }
        }
    }
    return false;
}
int main() {
    while(~scanf("%d%d%d",&l,&r,&c)) {
        if(l==0 && r==0 && c==0)
            break;
        memset(visited,false,sizeof(visited));
        memset(m,'.',sizeof(m));
        for (int i = 1; i <= l; ++i)
            for (int j = 1; j <= r; ++j)
                for (int k = 1; k <= c; ++k) {
                    cin >> m[i][j][k];
                    if(m[i][j][k]=='S') {
                        m[i][j][k] = '.';
                        startl = i, startx = j, starty = k;
                    }
                    if(m[i][j][k]=='E') {
                        m[i][j][k] = '.';
                        endlevel = i, endx = j, endy = k;
                    }
                }
        if(bfs())
            printf("Escaped in %d minute(s).\n",ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}