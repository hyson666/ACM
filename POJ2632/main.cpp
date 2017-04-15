#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int l,w;
int botnum,comnum;
struct robot
{
    int x;
    int y;
    char dir;
}rot[101];
bool judge(int n)
{
    if(rot[n].x<=0 || rot[n].x>l || rot[n].y<=0 || rot[n].y>w)
        return false;
    return true;
}
struct command
{
    int num;
    char type;
    int repeat;
}cc[101];
int crash(int n,int repeat,int dir)
{
    int ans=0;
    int comp=999999;
    int temp;
    for(int i=1;i<=botnum;++i)
    {
        if(i==n)
            continue;
        if(rot[i].x==rot[n].x)
        {
            if(dir==2)
            {
                if(rot[n].y>=rot[i].y) {
                    if (rot[n].y - repeat < rot[i].y) {
                        temp = abs(rot[n].y - repeat - rot[i].y);
                        if (temp < comp) {
                            comp = temp;
                            ans = i;
                        }
                    }
                }
            }
            if(dir==4)
            {
                if(rot[n].y<=rot[i].y) {
                    if (rot[n].y + repeat > rot[i].y) {
                        temp = abs(rot[n].y + repeat - rot[i].y);
                        if (temp < comp) {
                            comp = temp;
                            ans = i;
                        }
                    }
                }
            }
        }
        if(rot[i].y==rot[n].y)
        {
            if(dir==3)
            {
                if(rot[n].x>=rot[i].x) {
                    if (rot[n].x - repeat < rot[i].x) {
                        temp = abs(rot[n].x - repeat - rot[i].x);
                        if (temp < comp) {
                            comp = temp;
                            ans = i;
                        }
                    }
                }
            }
            if(dir==1)
            {
                if(rot[n].x<=rot[i].x) {
                    if (rot[n].x + repeat > rot[i].x) {
                        temp = abs(rot[n].x + repeat - rot[i].x);
                        if (temp < comp) {
                            comp = temp;
                            ans = i;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

char change(char dir,int repeat,int n)
{
    int t;
    int change=repeat%4;
    if(rot[n].dir=='W') t=1;
    if(rot[n].dir=='N') t=2;
    if(rot[n].dir=='E') t=3;
    if(rot[n].dir=='S') t=4;
    if(dir=='L')
        t-=change;
    if(dir=='R')
        t+=change;
    if(t== -3 || t%4==1)
        return 'W';
    if(t==-2 || t%4==2 )
        return 'N';
    if(t==-1 || t%4==3 )
        return 'E';
    if(t==0 || t%4==0)
        return 'S';
}

int main() {
    int k;
    cin>>k;
    while(k--)
    {
        cin.clear();
        cin>>l>>w;
        cin>>botnum>>comnum;
        for(int i=1;i<=botnum;++i)
        {
            cin>>rot[i].x>>rot[i].y>>rot[i].dir;
        }
        int flag=0;
        int bflag;
        for(int i=1;i<=comnum;++i)
            cin>>cc[i].num>>cc[i].type>>cc[i].repeat;
        for(int i=1;i<=comnum;++i)
        {
            if(cc[i].type=='F') {
                if (rot[cc[i].num].dir == 'W') {
                    rot[cc[i].num].x -= cc[i].repeat;
                    if (crash(cc[i].num,cc[i].repeat,1)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into robot " << crash(cc[i].num,cc[i].repeat,1)<<endl;
                        break;
                    }
                    if (!judge(cc[i].num)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into the wall"<<endl;
                        break;
                    }
                }
                if (rot[cc[i].num].dir  == 'E') {
                    rot[cc[i].num].x += cc[i].repeat;
                    if (crash(cc[i].num,cc[i].repeat,3)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into robot " << crash(cc[i].num,cc[i].repeat,3)<<endl;
                        break;
                    }
                    if (!judge(cc[i].num)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into the wall"<<endl;
                        break;
                    }
                }
                if (rot[cc[i].num].dir  == 'N') {
                    rot[cc[i].num].y += cc[i].repeat;
                    if (crash(cc[i].num,cc[i].repeat,2)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into robot " << crash(cc[i].num,cc[i].repeat,2)<<endl;
                        break;
                    }
                    if (!judge(cc[i].num)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into the wall"<<endl;
                        break;
                    }
                }
                if (rot[cc[i].num].dir  == 'S') {
                    rot[cc[i].num].y -= cc[i].repeat;
                    if (crash(cc[i].num,cc[i].repeat,4)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into robot " << crash(cc[i].num,cc[i].repeat,4)<<endl;
                        break;
                    }
                    if (!judge(cc[i].num)) {
                        flag=1;
                        cout << "Robot " << cc[i].num << " crashes into the wall"<<endl;
                        break;
                    }
                }
            }
            if(cc[i].type=='L' || cc[i].type == 'R')
            {
                rot[cc[i].num].dir = change(cc[i].type,cc[i].repeat,cc[i].num);
            }
        }
        if(flag==0)
            cout<<"OK"<<endl;
    }
    return 0;
}





