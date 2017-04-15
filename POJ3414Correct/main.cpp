#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int rear;
bool vis[110][110];
int A,B,C;
struct node
{
    int type;
    int num;
    int par;
    int step;
    int a,b;
}op[1001];
queue<node> que;
bool bfs()
{ node q;
    op[1].step=1,op[1].par=-1;
    op[2].step=1,op[2].par=-1;
    op[1].type=1,op[1].a=A,op[1].num=1,que.push(op[1]);
    op[2].type=2,op[2].b=B,op[2].num=2,que.push(op[2]);
    rear=2;
    while(!que.empty()){
        node p=que.front();
        if(p.a==C || p.b==C)
            return true;
        que.pop();
        int temp;
        for(int i=1;i<=6;++i){
            if(i==1 || i==2){
                ++rear;
                op[rear].num=rear;
                op[rear].a=p.a,op[rear].b=p.b;
                op[rear].par=p.num;
                op[rear].type=i;
                op[rear].step=p.step+1;
                if(i==1)
                    op[rear].a=A;
                else
                    op[rear].b=B;
                if(!vis[op[rear].a][op[rear].b]) {
                    que.push(op[rear]);
                    vis[op[rear].a][op[rear].b] = true;
                }
            }
            if(i==3 || i==4){
                ++rear;
                op[rear].num=rear;
                op[rear].a=p.a,op[rear].b=p.b;
                op[rear].par=p.num;
                op[rear].type=i;
                op[rear].step=p.step+1;
                if(i==3)
                    op[rear].a=0;
                else
                    op[rear].b=0;
                if(!vis[op[rear].a][op[rear].b]) {
                    que.push(op[rear]);
                    vis[op[rear].a][op[rear].b] = true;
                }
            }
            if(i==5 || i==6){
                ++rear;
                op[rear].num=rear;
                op[rear].a=p.a,op[rear].b=p.b;
                op[rear].par=p.num;
                op[rear].type=i;
                op[rear].step=p.step+1;
                if(i==5 && p.a>=B-p.b){
                    temp=B-p.b;
                    op[rear].a-=temp;
                    op[rear].b=B;
                }
                else if(i==5 && p.a<B-p.b){
                    op[rear].a=0;
                    op[rear].b=p.b+p.a;
                }
                else if(i==6 && p.b>=A-p.a){
                    temp=A-p.a;
                    op[rear].b-=temp;
                    op[rear].a=A;
                }
                else{
                    op[rear].b=0;
                    op[rear].a=p.b+p.a;
                }
                if(!vis[op[rear].a][op[rear].b]) {
                    que.push(op[rear]);
                    vis[op[rear].a][op[rear].b] = true;
                }
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d%d", &A, &B, &C);
    if (bfs()) {
        node ans = que.front();
        vector<node> toput;
        for (int i = ans.num; i != -1; i = op[i].par) {
            toput.push_back(op[i]);
        }
        reverse(toput.begin(), toput.end());
        vector<node>::iterator iter;
        printf("%d\n", ans.step);
        for (iter = toput.begin(); iter != toput.end(); ++iter) {
            switch ((*iter).type) {
                case 1: {
                    puts("FILL(1)");
                    break;
                }
                case 2: {
                    puts("FILL(2)");
                    break;
                }
                case 3: {
                    puts("DROP(1)");
                    break;
                }
                case 4: {
                    puts("DROP(2)");
                    break;
                }
                case 5: {
                    puts("POUR(1,2)");
                    break;
                }
                case 6: {
                    puts("POUR(2,1)");
                    break;
                }
            }
        }
    }
    else
        puts("impossible");
    return 0;
}