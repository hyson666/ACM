#include <iostream>
using namespace std;
const int sonnum=100000;
char str[100010];
//结点基本结构。
typedef struct node
{
    int num;
    bool terminal;
    struct node *next[sonnum];
}
*trie,node;

//创建一个新的结点。
void init_trie(trie &p)
{
    p = (trie)malloc(sizeof(node));
    for(int i=0;i<26;++i)
        p->next[i]=NULL;
    p->terminal=false;
    p->num=0;
}

//插入操作
trie root;
void insert(trie p,char str[])
{
    int k=0;
    while(str[k]!='\0')
    {
        if(!p->next[str[k]-'a'])
        {
            trie q;
            init_trie(q);
            p->next[str[k]-'a']=q;
        }
        p=p->next[str[k]-'a'];
        p->num++;
        k++;
    }
    p->terminal=true;
}

//查找操作
int find(trie p,char s[])
{
    int k=0;
    while(str[k]!='\0' && p->next[s[k]-'a'])
    {
        p=p->next[s[k]-'a'];
        ++k;
    }
    if(str[k]=='\0')
        return p->num;
    return 0;
}
