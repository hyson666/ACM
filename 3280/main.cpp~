#include<iostream>
#include<algorithm>
#define inf 1e9;
int DP[2048][2048];
char s[2048];
int cost[10001];
using namespace std;
int main()
{
    string s;
    int n,m;
    cin>>m>>n;
    cin>>s;
    char a;
    int cost1,cost2;
    for(int i=0;i<m;++i)
    {
        cin>>a>>cost1>>cost2;
        cost[a]=min(cost1,cost2);
    }
    for(int k=1;k<n;++k)
    {
        for(int i=0,j=k;j<n;++i,++j)
        {
            //只对用到的初始化
            DP[i][j]=inf;
            if(s[i]==s[j])
                DP[i][j]=DP[i+1][j-1];
            else
            {
                DP[i][j]=min(DP[i+1][j]+cost[s[i]],DP[i][j]);
                DP[i][j]=min(DP[i][j-1]+cost[s[j]],DP[i][j]);
            }
        }
    }
    cout<<DP[0][n-1]<<endl;
    return 0;
}
