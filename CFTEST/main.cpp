#include <iostream>
#include<cmath>
using namespace std;
int main() {
    long long n,k;
    cin>>n>>k;
    long long temp=sqrt(n);
    int flag=0;
    if(k>temp){
         flag=1;
         k/=2;
    }
    long long count=1;
    long long i;
    for(i=2;i<=temp;++i){
        if(n%i==0)
            count++;
        if()
            break;
    }
    if(flag==1)
        i=n/i;
    if(n%i==0)
        cout<<i<<endl;
    else if(n==1)
        cout<<1<<endl;
    else
        cout<<i<<endl;
}