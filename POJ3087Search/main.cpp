#include <iostream>
#include <string>
#include <map>
using namespace std;
string str1,str2,str3,ans;
int t,len;
int main() {
    cin>>t;
    map<string,int> hash;
    int times=1;
    while(t--){
        hash.clear();
        scanf("%d",&len);
        cin>>str2;
        cin>>str1;
        cin>>str3;
        string::iterator iter1=str1.begin(),iter2=str2.begin();
        int flag=1;
        int cnt=1;
        while(flag){
            ans="";
            while(iter1!=str1.end()) {
                ans=ans+*iter1;
                ans=ans+*iter2;
                ++iter1,++iter2;
            }
            if(ans!=str3){
                if(!hash[ans]) {
                    ++cnt;
                    ++hash[ans];
                }
                else{
                    printf("%d -1\n",times);
                    flag=0;
                    ++times;
                }
                iter2=ans.begin(),str2="";
                for(int j=0;j<len;++j) {
                    str2+=*iter2;
                    iter2++;
                }
                iter1=ans.begin()+len,str1="";
                for(int j=len;j<2*len;++j){
                    str1+=*iter1;
                    iter1++;
                }
                iter1=str1.begin(),iter2=str2.begin();
            }
            else{
                printf("%d %d\n",times,cnt);
                flag=0;
                ++times;
            }
        }
    }
    return 0;
}