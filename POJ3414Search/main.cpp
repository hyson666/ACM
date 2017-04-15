#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int A,B,C;
bool vis[110][110];
struct node
{
    char type;
    int num1,num2;
    int step;
    int a,b;
    int num;
    int father;
}op[1001];
queue<node> que;
bool bfs()
{
    op[1].num=1,op[1].father=-1;
    op[1].type='F',op[1].num1=1,op[1].step=1;
    que.push(op[1]);
    op[1].type='F',op[1].num1=2,op[1].step=1;
    que.push(op[1]);
    vis[op[1].a][op[1].b]=true;
    node p;
    int temp;
    while(!que.empty()){
        p=que.front();
        if(p.type=='F'){
            if(p.num1==1)
                op[p.num].a=A;
            else
                op[p.num].b=B;
        }
        if(p.type=='D'){
            if(p.num1==1)
                op[p.num].a=0;
            else
                op[p.num].b=0;
        }
        if(p.type=='P'){
            if(p.num2==2){
                if(B-p.b<=p.a){
                    temp=B-op[p.num].b;
                    op[p.num].a-=temp;
                    op[p.num].b=B;
                }
                else{
                    .b+=p.a;
                    op[p.num].a=0;
                }
            }
            if(p.num2==1){
                if(A-p.a<=p.b){
                    temp=A-p.a;
                    p.b-=temp;
                    p.a=A;
                }
                else{
                    p.a+=p.b;
                    p.b=0;
                }
            }
        }
        if(p.a==C || p.b==C)
            return true;
        que.pop();
        int k=p.num;
        if(!vis[p.a][p.b]) {
            op[++p.num].type = 'F', op[p.num].num1 = 1, op[p.num].num=p.num,que.push(op[p.num]);
            op[p.num].step = p.step + 1, op[p.num].a = p.a, op[p.num].b = p.b ,op[p.num].father=k,que.push(op[p.num]);
            op[++p.num].type = 'F', op[p.num].num1 = 2, op[p.num].num=p.num,que.push(op[p.num]);
            op[p.num].step = p.step + 1, op[p.num].a = p.a, op[p.num].b = p.b ,op[p.num].father=k,que.push(op[p.num]);
            op[++p.num].type = 'D', op[p.num].num1 = 1, op[p.num].num=p.num,que.push(op[p.num]);
            op[p.num].step = p.step + 1, op[p.num].a = p.a, op[p.num].b = p.b ,op[p.num].father=k,que.push(op[p.num]);
            op[++p.num].type = 'D', op[p.num].num1 = 2, op[p.num].num=p.num,que.push(op[p.num]);
            op[p.num].step = p.step + 1, op[p.num].a = p.a, op[p.num].b = p.b ,op[p.num].father=k,que.push(op[p.num]);
            op[++p.num].type = 'P', op[p.num].num1 = 1, op[p.num].num=p.num,op[p.num].num2 = 2;
            op[p.num].step = p.step + 1, op[p.num].a = p.a, op[p.num].b = p.b ,op[p.num].father=k,que.push(op[p.num]);
            op[++p.num].type = 'P', op[p.num].num1 = 2, op[p.num].num=p.num,op[p.num].num2 = 1, que.push(op[p.num]);
            op[p.num].step = p.step + 1, op[p.num].a = p.a, op[p.num].b = p.b ,op[p.num].father=k,que.push(op[p.num]);
            vis[p.a][p.b]=true;
        }
    }
    return false;
}
int main(){
    while(~scanf("%d%d%d",&A,&B,&C)){
        node ans;
        if(bfs()){
            ans=que.front();
            vector<node> toput;
            for(int i=ans.num;i!=-1;i=op[i].father) {
                toput.push_back(op[i]);
            }
            reverse(toput.begin(),toput.end());
            printf("%d\n",ans.step);
            vector<node>::iterator iter ;
            for(iter=toput.begin();iter!=toput.end();++iter){
                if((*iter).type=='F')
                    printf("FILL(%d)\n",(*iter).num1);
                if((*iter).type=='D')
                    printf("DROP(%d)\n",(*iter).num1);
                if((*iter).type=='P')
                    printf("POUR(%d,%d)\n",(*iter).num1,(*iter).num2);
            }
        }
        else
            printf("impossible\n");
    }
    return 0;
}
