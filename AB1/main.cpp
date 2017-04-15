#include <iostream>
using namespace std;
int main() {
    int a,sum;
    int n;
    cin>>n;
    int k;
    while(n--) {
        sum=0;
        cin>>k;
        while(k--) {
            cin >> a;
            sum += a;
        }
        cout<<sum<<endl;
        if(n!=0)
        cout<<endl;
    }
    return 0;
}