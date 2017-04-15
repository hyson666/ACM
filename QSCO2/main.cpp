#include <iostream>
#include <cstring>
using namespace std;
int MAX;
char str[100010];
int main(){
    int v;
    cin>>v;
    while(v--){
        MAX=0;
        scanf("%s",str);
        int n=(int)strlen(str);
        int cnt=0;
        int flag=0;
        for(int i=0;i<n;++i){
            if(str[i]==')' && flag)
                cnt=0;
            if(str[i]=='(' && str[i+1]==')'){
                if(!flag)
                    cnt=2;
                else
                    cnt+=2;
                int l=i-1,r=i+2;
                while(str[l]=='(' && str[r]==')'){
                    l--;r++;
                    cnt+=2;
                    flag=1;
                }
                i=r-1;
                MAX=max(MAX,cnt);
            }
        }
        cout<<MAX<<endl;
    }
}