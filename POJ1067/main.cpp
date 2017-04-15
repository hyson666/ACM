#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b){
        if(a>b)
            swap(a,b);
        double d=b-a;
        if(a==floor(((sqrt(5.0)+1)/2.0)*d))
            puts("0");
        else
            puts("1");
    }
    return 0;
}