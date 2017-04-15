#include <iostream>
#include <cstring>
using namespace std;
bool HASH[12];
int table[100010];
int ans=0;
void init_table()
{
    int flag;
    for(int i=1;i<=100000;++i){
        memset(HASH,false,sizeof(HASH));
        flag=0;
        int temp=i;
        while(temp){
            int j=temp%10;
            if(!HASH[j])
               HASH[j]=true;
            else{
                flag=1;
                break;
            }
            temp/=10;
        }
        if(flag==0) {
            ++ans;
            table[i]=ans;
        }
        else
            table[i]=ans;
    }
}

int main() {
    init_table();
    int t;
    cin>>t;
    int a,b;
    while(t--){
        scanf("%d%d",&a,&b);
        cout<<table[b]-table[a-1]<<endl;
    }
    return 0;
}


