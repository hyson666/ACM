#include <iostream>
#include <queue>
using namespace std;
bool visited[100010];
struct node
{
    int step,pos;
};
int main() {
    int s,e;
    while(~scanf("%d%d",&s,&e)){
        queue<node> que;
        node q;
        q.pos=s,q.step=0;
        que.push(q);
        visited[s]=true;
        node temp;
        while(que.size()){
            node p=que.front();
            que.pop();
            if(p.pos==e){
                cout<<p.step<<endl;
                break;
            }
            for(int i=1;i<=3;++i){
                if(i==1 && p.pos<e) temp.pos=p.pos+1;
                if(i==2) temp.pos=p.pos-1;
                if(i==3 && p.pos<e) temp.pos=2*p.pos;
                temp.step=p.step+1;
                if(temp.pos<=100000 && !visited[temp.pos]) {
                    visited[temp.pos]=true;
                    que.push(temp);
                }
            }
        }
    }
    return 0;
}