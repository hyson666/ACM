#include <iostream>
#include <vector>
#define maxn 1000000+10
using  namespace std;
vector<int> tree[maxn];
vector<int> ans;
int val[maxn];
int n,sum;
int s[maxn];
int root;
int dfs(int k)
{
    s[k]=val[k];
    for(int i=0;i<tree[k].size();++i){
        int u=tree[k][i];
        dfs(u);
        s[k]+=s[u];
    }
    if(s[k]==sum && k!=root && k!=0){
        s[k]=0;
        ans.push_back(k);
    }
}
int main() {
    cin>>n;
    int par;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&par,&val[i]);
        tree[par].push_back(i);
        if(par==0) root=i;
        sum+=val[i];
    }
    if(sum%3){
        puts("-1");
    }
    else{
        sum/=3;
        dfs(0);
        if(ans.size()>=2){
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
        else{
            puts("-1");
        }
    }
    return 0;
}