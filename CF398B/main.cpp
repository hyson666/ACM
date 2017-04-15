#include <iostream>
using namespace std;
int times[100010];
bool emp[100010];
int main() {
    int start, end, t;
    scanf("%d%d%d", &start, &end, &t);
    int v;
    for(int i=0;i<v;++i) {
        scanf("%d", &times[i]);
        if(times[i]<=start)
            start+=t;
    }
    int flag=0;
    if(start>end)
        cout<<times[0]-1<<endl;
    else{
        for(int i=1;i<v;++i){
            if(times[i]-times[i-1]>t){
                cout<<times[i-1]+t<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<start<<endl;
    }
}