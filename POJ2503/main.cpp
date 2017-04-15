#include <iostream>
#include <algorithm>
using namespace std;
char ques[20];
int pos;
struct node
{
    char word[20],transfer[20];
}dic[100010];
bool cmp(node a,node b)
{
    return strcmp(a.word,b.word)<0;  //这样写表明是按照升序排列的。
}
int binsearch(char *s)
{
    int l=0,r=pos-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if (strcmp(ques, dic[mid].word) == 0)
            return mid;
        else if(strcmp(ques,dic[mid].word)>0) l=mid+1; //说明要查找的词语在字典序的后面。
        else r=mid-1;
    }
    return -1;  //没有在有效下表中找到返回-1。
}
int main() {
    char t;
    while(scanf("%s%c",dic[pos].transfer,&t)!=EOF)
    {
        if(t=='\n'){
            strcpy(ques,dic[pos].transfer);
            break;
        }
        else {
            scanf("%s",dic[pos].word);
            pos++;
        }
    }
    sort(dic,dic+pos,cmp);
    int ans=binsearch(ques);
    if(ans==-1)
        puts("eh");
    else
        printf("%s\n",dic[ans].transfer);
    while(~scanf("%s",ques)){
        ans=binsearch(ques);
        if(ans==-1)
            puts("eh");
        else
            printf("%s\n",dic[ans].transfer);
    }
    return 0;
}