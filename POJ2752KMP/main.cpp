#include <iostream>
#include <cstring>
using namespace std;
char str[400000+10];
int Next[400000+10];
int ans[400000+10];
int len;
void get_next()
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<len){
        if(j==-1 || str[i]==str[j]){
            Next[++i]=++j;
        }
        else
            j=Next[j];
    }
}
int main() {
    while(~scanf("%s",str)){
        ans[0]=len=strlen(str);
        get_next();
        int num=0;
        while(Next[len]>0){
            ans[++num]=Next[len];
            len=Next[len];
        }
        while(num!=-1){
            printf("%d ",ans[num]);
            num--;
        }
        putchar('\n');
    }
    return 0;
}