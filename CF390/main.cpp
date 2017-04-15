#include <iostream>
#define inf 99999999999999999
using namespace std;
int main() {
    int level;
    int n;
    cin>>n;
    int div,change;
    long long rank=inf;
    int flag=0;
    int flag1=0;
    int flag2=0;
    while(n--){
        cout<<rank<<endl;
        cin>>change>>div;
        if(div==1){
            flag2=1;
            if(rank<1900){
                cout<<"Impossible"<<endl;
                break;
            }
            rank+=change;
        }
        if(div==2){
            rank+=change;
            if(flag==0){
                rank-=inf;
                rank+=1899;
                if(rank<=1900)
                    rank=1899;
                flag=1;
            }
            if(rank-change>1900 && flag==1 && flag2==1){
                flag1=1;
                cout<<"Impossible"<<endl;
                break;
            }
            else if(rank>1900 && flag==1 && flag2==0){
                continue;
            }
        }
    }
    if(flag2==0){
        rank-=inf;
    }
    if(flag1==0) {
        if (rank > 999999999999)
            cout << "Infinity" << endl;
        else
            cout << rank << endl;
    }
    return 0;
}