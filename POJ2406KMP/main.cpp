#include <iostream>
#define MAX_N 1000000+10
using namespace std;
char str[MAX_N];
int Next[MAX_N];
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
        if(strcmp(str,".")==0)
            break;
        len=strlen(str);
        get_next();
        if(len%(len-Next[len]))
            puts("1");
        else
            printf("%d\n",len/(len-Next[len]));
    }
    return 0;
}