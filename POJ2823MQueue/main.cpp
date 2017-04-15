#include <iostream>
#define maxn 1000000+10
using  namespace std;
int A[maxn];
int min_Q[maxn];
int max_Q[maxn];
int p[maxn];
int Min[maxn];
int Max[maxn];
int n,k;
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&A[i]);
    }
    int maxhead=1,maxtail=0,minhead=1,mintail=0;
    //首先以确定长度初始化递增队列和递减队列。
    int i;
    for(i=0;i<k-1;++i){
        while(maxhead<=maxtail && max_Q[maxtail]<=A[i])  //大的元素往队首冒。
            maxtail--;
        max_Q[++maxtail]=A[i];
        p[maxtail]=i;
    }
    while(i<n){
        while(maxhead<=maxtail && max_Q[maxtail]<=A[i])
            maxtail--;
        max_Q[++maxtail]=A[i];
        p[maxtail]=i;
        while(p[maxhead]<i-k+1)  //长度为r-l+1,如果maxhead小于i-长度,说明队首过时了。
            maxhead++;
        Max[i-k+1]=max_Q[maxhead];
        ++i;
    }
    for(i=0;i<k-1;++i){
        while(minhead<=mintail && min_Q[mintail]>=A[i])
            mintail--;
        min_Q[++mintail]=A[i];
        p[mintail]=i;
    }
    while(i<n){
        while(minhead<=mintail && min_Q[mintail]>=A[i])
            mintail--;
        min_Q[++mintail]=A[i];
        p[mintail]=i;
        while(p[minhead]<i-k+1)
            minhead++;
        Min[i-k+1]=min_Q[minhead];
        ++i;
    }
    for(int j=0;j<n-k+1;++j)
        printf("%d ",Min[j]);
    puts(" ");
    for(int j=0;j<n-k+1;++j)
        printf("%d ",Max[j]);
    return 0;
}