#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10;    //题目总结点不超过10个。
char input[100];
int id[256],letter[maxn];
int main() {
    while(~scanf("%s",input) && input[0]!='#'){
        int n=0;
        for(char ch='A';ch<='Z';++ch){
            if(strchr(input,ch)!=NULL){     //快速找到第一次出现的位置。
                id[ch]=n++;     //找到这个字符就给这个字符编号,从n=0开始。
                letter[id[ch]]=ch;      //第i个编号字符对应的是哪个字母记录。
            }
        }
        //根据上面的处理之后就可以开始建图了。
        int len = (int)strlen(input),p=0,q=0;
        vector<int> u,v;
        //u,v从0开始,u是节点表,v是对应的连接点表。因为个数是确定的,所以是一维的。
        for(;;){
            while(p<len && input[p]!=':') p++;  //移位置到':"处。
            if(p == len) break;
            while(q<len && input[q]!=';') q++;
            for(int i=p+1;i<q;++i){
                u.push_back(id[input[p-1]]);
                v.push_back(id[input[i]]);
            }
            ++p;++q;
        }
        //枚举全排列。
        int P[maxn],bestP[maxn],pos[maxn],ans=n;
        for(int i=0;i<n;++i) P[i]=i;    //总共编号了n个结点,用来枚举。
        do{
            for(int i=0;i<n;++i) pos[P[i]]=i;
            int bandwidth = 0;
            for(int i=0;i<u.size();++i)
                bandwidth = max(bandwidth,abs(pos[u[i]]-pos[v[i]]));
            if(bandwidth<ans){
                ans = bandwidth;
                memcpy(bestP,P,sizeof(P));
            }
        }while(next_permutation(P,P+n));
        for(int i=0;i<n;++i) printf("%c ",letter[bestP[i]]);
        printf("-> %d\n",ans);
    }
    return 0;
}