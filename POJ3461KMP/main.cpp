#include <iostream>
#include <cstring>
using namespace std;
int Next[10010];
int len1,len2;
char str[10010];
char p[1000010];
void getNext()
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<len1){
        if(j==-1 || str[i]==str[j]){
            Next[++i]=++j;
        }
        else
            j=Next[j];
    }
}
int KMP()
{
    int i=0,j=0;
    int ans=0;
    while(i<len2){
        if(j==-1 || p[i]==str[j])
            ++i,++j;
        else
            j=Next[j];
        if(j==len1)
            ++ans,j=Next[j];
    }
    return ans;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        scanf("%s",str);
        len1=strlen(str);
        getNext();
        scanf("%s",p);
        len2=strlen(p);
        printf("%d\n",KMP());
    }
    return 0;
}