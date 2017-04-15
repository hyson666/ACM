#include<iostream>
#include <queue>
#define MAX_N 305
using namespace std;
int sx,sy;
bool visted[MAX_N][MAX_N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

struct node
{
    int x;
    int y;
    int t;
    int time;
}pos[MAX_N][MAX_N];

int  bfs()
{
    queue<node> que;
    que.push(pos[sx][sy]);
    visted[sx][sy]=true;
    while(que.size())
    {
        node p=que.front();
        que.pop();
        if(pos[p.x][p.y].t==9999999)
        {
            if(p.x!=0 || p.y!=0)
                return p.time;
        }
        for(int i=0;i<4;++i)
        {
            int nx=p.x+dx[i];
            int ny=p.y+dy[i];
            if(nx>=0 && ny>=0 && !visted[nx][ny] && (p.time+1)<pos[nx][ny].t)
            {
                pos[nx][ny].time = p.time+1;
                visted[nx][ny]=true;
                que.push(pos[nx][ny]);
            }
        }
    }
    return -1;
}

int main()
{
    int m;
    cin>>m;
    int tx,ty;
    int time;
    for(int i=0;i<MAX_N;++i)
    {
        for(int j=0;j<MAX_N;++j)
        {
            if(i!=0 || j!=0)
                pos[i][j].t=9999999;
            pos[i][j].x=i;
            pos[i][j].y=j;
        }
    }
    while(m--)
    {
        cin>>tx>>ty>>time;
        pos[tx][ty].t=min(time,pos[tx][ty].t);
        pos[tx][ty].x=tx;
        pos[tx][ty].y=ty;
        for(int i=0;i<4;++i)
        {
            if(tx+dx[i]>=0 && ty+dy[i]>=0)
            pos[tx+dx[i]][ty+dy[i]].t=min(pos[tx+dx[i]][ty+dy[i]].t,time);
        }
    }
    int ans=bfs();
    cout<<ans<<endl;
    return 0;
}
