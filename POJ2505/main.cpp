#include <iostream>
using namespace std;
int i;
struct node
{
    long long lower;
    long long upper;
    int swin;
}table[16];
void inittable()
{
    table[1].lower=2;
    table[1].upper=9;
    table[1].swin=1;
    table[2].lower=10;
    table[2].upper=18;
    table[2].swin=0;
    for(i=3;;++i){
        table[i].lower=table[i-1].upper+1;
        if(i%2) {
            table[i].swin = 1;
            table[i].upper = table[i-1].upper * 9;
        }
        else {
            table[i].swin = 0;
            table[i].upper = table[i-1].upper * 2;
        }
        if(table[i].upper>=4294967295)
            break;
    }
};
int binsearch(long long n)
{
    int l=1;
    int r=i;
    while(l<=r){
        int mid=(l+r)/2;
        if(table[mid].lower<=n && n<=table[mid].upper)
            return table[mid].swin;
        else if(n<table[mid].lower) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
int main() {
    long long n;
    inittable();
    while(cin>>n) {
        if(binsearch(n))
            cout<<"Stan wins."<<endl;
        else
            cout<<"Ollie wins."<<endl;
    }
    return 0;
}