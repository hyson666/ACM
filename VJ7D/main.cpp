#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int book[10][10];
int a[6][6];
struct note
{
    int x;
    int y;
    int f;
    int step;
    int far;
};
int main()
{
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cin>>a[i][j];
        }
    }
    struct note queue[2000];
    int next[4][2]={{0,1},
                    {1,0},
                    {0,-1},
                    {-1,0}};
    int startx=0,starty=0,head=1,tail=1;
    int tx,ty,k,flag=0;
    queue[0].far=-1;
    queue[tail].x=startx;
    queue[tail].y=starty;
    queue[tail].step=0;
    queue[tail].f=0;
    queue[tail].far=0;
    book[startx][starty]=1;
    ++tail;
    while(head<tail){
        for(int k=0;k<4;++k){
            tx=queue[head].x+next[k][0];
            ty=queue[head].y+next[k][1];
            if(tx<0 || ty<0 || tx>4 || ty>4 )
                continue;
            if(a[tx][ty]!=1 && book[tx][ty]==0){
                queue[tail].x=tx;
                queue[tail].y=ty;
                book[tx][ty]=1;
                queue[tail].step=queue[head].step + 1;
                queue[tail].far=head;
                ++tail;
            }
            if(tx==4 && ty==4){
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
        ++head;
    }
    tail--;
    vector<note> path;
    while(queue[tail].far!=-1){
        path.push_back(queue[tail]);
        tail=queue[tail].far;
    }
    reverse(path.begin(),path.end());
    vector<note>::iterator iter=path.begin();
    while(iter!=path.end()){
        cout<<"("<<iter->x<<", "<<iter->y<<")"<<endl;
        iter++;
    }
    return 0;
}
