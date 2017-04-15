#include <iostream>
#include <cstring>
using namespace std;
int c,r;
int Next[10010];
char str[10010][80];
int num[10010];  //记录哪个长度符合要求,必定靠近最左上。
void getNext_r(int n)
{
    memset(Next,0,sizeof(Next));
    int i=0,j=-1;
    Next[0]=-1;
    while(i<r){
        if(j==-1 || str[n][i]==str[n][j])
            Next[++i]=++j;
        else
            j=Next[j];
    }
}
void count_fun()
{
    int j=r;
    while(j>0){
        num[r-Next[j]]++;
        j=Next[j];
    }
}
void getNext_c()  //把每一行当做整体来处理求Next,又这题的性质可以求出列的Next。
{
    memset(Next,0,sizeof(Next));
    int i=0,j=-1;
    Next[0]=-1;
    while(i<c){
        if(j==-1 || strcmp(str[i],str[j])==0)
            Next[++i]=++j;
        else
            j=Next[j];
    }
}
int main(){
    while(~scanf("%d%d",&c,&r)){
        memset(num,0,sizeof(num));
        for(int i=0;i<c;++i){
            scanf("%s",str[i]);
            getNext_r(i);
            count_fun();
        }
        int h,w;
        for(int i=0;i<=r;++i){
            if(num[i]==c){
                w=i;
                break;
            }
        }
        getNext_c();
        h=c-Next[c];
        printf("%d\n",w*h);
    }
    return 0;
}
