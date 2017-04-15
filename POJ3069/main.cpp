#include <iostream>
#include <algorithm>
using namespace std;
int x[1010];
int main() {
    int n,r;
    while(cin>>r>>n)
    {
        if(n==-1&&r==-1)
            break;
        int num=0;
        while(num<n)
            cin>>x[num++];
        sort(x,x+n);
        int i=0,s;
        int ans=0;
        while(i<n)
        {
            s=x[i++];
            while(i<n && x[i]<=s+r)
                i++;
            int p=i-1;
            while(i<n && x[i]<=x[p]+r)
                i++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}