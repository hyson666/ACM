#include <iostream>
#include <algorithm>
using namespace std;
int n,shift;
struct node
{
    int begin,end;
}cow[30010];
bool cmp(node a,node b)
{
    return a.begin<b.begin;
}
int solve()
{
    int begin=0;
    int end=0;
    int index=0;
    int ans=0;
    while(end<shift)
    {
        begin=end+1;
        for(int i=index;i<n;++i){
            if(cow[i].begin<=begin){
                end=max(end,cow[i].end);
            }
            else{
                index=i;
                break;
            }
        }
        if(begin>end)
            return -1;
        else
            ans++;
    }
    return ans;
}
int main() {
    cin>>n>>shift;
    for(int i=0;i<n;++i)
        scanf("%d%d",&cow[i].begin,&cow[i].end);
    sort(cow,cow+n,cmp);
    cout<<solve()<<endl;
    return 0;
}
