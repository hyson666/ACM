#include <iostream>
#include <cstring>
using namespace std;
bool HASH[11];
int num;
bool ex;
void check(int n)
{
    memset(HASH,false,sizeof(HASH));
    if(n<10000)
        HASH[0]=true;
    int temp=n,num1,num2=n;
    while(temp){
        int ask=temp%10;
        if(HASH[ask])
            return;
        HASH[ask]=true;
        temp/=10;
    }
    num1=temp=n*num;
    while(temp){
        int ask=temp%10;
        if(HASH[ask])
            return;
        HASH[ask]=true;
        temp/=10;
    }
    if(num1>10000) {
        ex=true;
        printf("%05d / %05d = %d\n", num1, num2, num);
    }
}
int main() {
    int t=0;
    while(~scanf("%d",&num)){
        if(num==0)
            break;
        if(t++) printf("\n");
        ex=false;
        for(int i=1234;i<=100000;++i){
            if(i*num>=100000)
                break;
            check(i);
        }
        if(!ex) {
            printf("There are no solutions for %d.\n",num);
        }
    }
    return 0;
}