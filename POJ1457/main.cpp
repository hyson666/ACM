#include <iostream>
#include <algorithm>
using namespace std;
int num;
int A[100010];
int B[100010];
int C[100010];
int n;
bool visted[10010];
int ans;
bool HASH[10010];
void dfs(int times)
{
    int temp;
    int flag;
    int tempans;
    int k;
    if(times==num+1) {
        tempans=1;
        int checkcount=0;
        for(int i=1;i<=num;++i){
            checkcount+=B[i];
        }
        if(checkcount!=A[n])
            return;
        k=1;
        memset(C,0,sizeof(C));
        for(int i=1;i<=num;++i){
            temp=0;
            tempans*=B[i];
            flag=0;
            for(int j=i;j<=num;++j){
                temp+=B[j];
                C[k++]=temp;
                if(!HASH[temp]){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                return;
        }
        sort(C+1,C+n+1);
        int judge=0;
        for(int i=1;i<=n;++i){
            if(A[i]!=C[i]){
                judge=1;
                break;
            }
        }
        if(judge==0)
            ans=tempans;
        return;
    }
    for(int i=1;i<=n;++i){
        if(!visted[i]){
            B[times]=A[i];
            visted[i]=true;
            dfs(times+1);
            visted[i]=false;
            if(ans!=0)
                break;
        }
    }
}
int main()
{
    while(cin>>n){
        ans=0;
        int temp=2*n;
        for(int i=2;i<=n;++i){
            if(i*(i-1)==temp){
                num=i;
                break;
            }
        }
        num--;
        for(int i=1;i<=n;++i){
            scanf("%d",&A[i]);
            HASH[A[i]]=true;
        }
        temp=0;
        dfs(1);
        if(n==1)
            ans=A[1];
        if(ans!=0)
            cout<<ans<<endl;
        else
            cout<<"No solution"<<endl;
    }
}