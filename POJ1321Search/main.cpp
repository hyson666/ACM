#include <iostream>
using namespace std;
int n,k;
char m[10][10];
int ans;
bool visited[10];
void dfs(int row,int num)
{
    if(num==k) {
        ans++;
        return;
    }
    if(row>n)
        return;
    for(int i=0;i<n;++i){
        if(m[row][i]=='#' && !visited[i]){
            visited[i]=true;
            dfs(row+1,num+1);
            visited[i]=false;
        }
    }
    dfs(row+1,num);
}
int main() {
    while(~scanf("%d %d\n",&n,&k)){
        memset(visited,false,sizeof(visited));
        memset(m,'.',sizeof(m));
        if(n==-1 && k==-1)
            break;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>m[i][j];
        ans=0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}