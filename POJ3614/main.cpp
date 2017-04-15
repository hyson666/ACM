#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > que;
int cnum,lnum;
struct node
{
    int spfmin,spfmax;
}cow[3030];
struct node1
{
    int level,num;
}lotion[3030];
bool cmp(node a,node b)
{
    return a.spfmin<b.spfmin;
}
bool cmp1(node1 a,node1 b)
{
    return a.level<b.level;
}
int solve()
{
     int ans=0;
     int mark=0;
     int maxspf;
     for(int i=0;i<lnum;++i){
         while(mark<cnum && cow[mark].spfmin<=lotion[i].level){
             que.push(cow[mark].spfmax);
             mark++;
         }
         while(!que.empty() && lotion[i].num){
             maxspf=que.top();
             que.pop();
             if(maxspf>=lotion[i].level) {
                 ans++;
                 lotion[i].num--;
             }
         }
     }
    return  ans;
}
int main() {
    cin>>cnum>>lnum;
    for(int i=0;i<cnum;++i)
        scanf("%d%d",&cow[i].spfmin,&cow[i].spfmax);
    int level,num;
    for(int i=0;i<lnum;++i){
        scanf("%d%d",&lotion[i].level,&lotion[i].num);
    }
    sort(cow,cow+cnum,cmp);
    sort(lotion,lotion+lnum,cmp1);
    printf("%d\n",solve());
}