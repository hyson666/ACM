#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,c,f;
priority_queue<int> que1,que2;
int upper[100010],lower[100010];
struct node
{
    int score,need;
}cow[100010];
bool cmp(node a,node b)
{
    return a.score>b.score;
}
int main() {
    cin>>n>>c>>f;
    for(int i=1;i<=c;++i){
        scanf("%d%d",&cow[i].score,&cow[i].need);
    }
    sort(cow+1,cow+c+1,cmp);
    int temp=(n-1)/2;
    int mark=-1;
    int flag=0;
    int total1=0,total2=0;
    for(int j=1;j<=1+temp-1;++j){
        total1+=cow[j].need;
        que1.push(cow[j].need);
    }
    for(int j=c-temp+1;j<=c;++j){
        total2+=cow[j].need;
        que2.push(cow[j].need);
    }
    for(int i=1+temp;i<=c-temp;++i){
        upper[i]+=total1;
        total1+=cow[i].need;
        que1.push(cow[i].need);
        total1-=que1.top();
        que1.pop();
    }
    for(int i=c-temp;i>=1+temp;--i){
        lower[i]+=total2;
        total2+=cow[i].need;
        que2.push(cow[i].need);
        total2-=que2.top();
        que2.pop();
    }
    for(int i=1+temp;i<=c-temp;++i){
        if(lower[i]+upper[i]+cow[i].need<=f){
            mark=i;
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<cow[mark].score<<endl;
    else
        cout<<-1<<endl;
    return 0;
}