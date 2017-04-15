#include <iostream>
#include <queue>
#define ll long long
ll p[100010];
ll num[100010];
ll note[100010];
using namespace std;
int main() {
    queue<ll> s[100010];
    ll n;
    cin>>n;
    char c;
    ll a,b;
    for(int i=0;i<=n;++i) {
        p[i] = 1;
        note[i] = i;
        s[i].push(i);
    }
    while(n--){
        cin>>c;
        if(c=='M') {
            cin>>a>>b;
            if (note[a] != b) {
                int t=note[a];
                while(!s[t].empty()) {
                    s[b].push(s[t].front());
                    num[s[t].front()]+=p[b];
                    note[s[t].front()]=b;
                    s[t].pop();
                }
                p[b]+=p[a];
                p[a]=0;
            }
        }
        if(c=='C'){
            cin>>a;
            cout<<num[a]<<endl;
        }
    }
    return 0;
}