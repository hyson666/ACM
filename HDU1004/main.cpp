#include <iostream>
using namespace std;
//结点基本结构。
typedef struct node
{
    int num;
    bool terminal;
    struct node *next[26];
} *trie,node;

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
int find(trie p,char str[])
{
    int k=0;
    while(str[k]!='\0' && p->next[str[k]-'a'])
    {
        p=p->next[str[k]-'a'];
        ++k;
    }
    if(str[k]=='\0')
        return p->num;
    return 0;
}

int main() {
    int n;
    while(~scanf("%d",&n) && n){
        init_trie(root);
        char ch[1005][17];
        for(int i=0;i<n;++i) {
            cin >> ch[i];
            insert(root,ch[i]);
        }
        int MAX=0,tem,f;
        for(int i=0;i<n;++i){
            tem=find(root,ch[i]);
            if(tem>MAX){
                MAX=tem;
                f=i;
            }
        }
        cout<<ch[f]<<"\n";
    }
    return 0;
}