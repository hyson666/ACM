#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin>>s;
    string::iterator iter=s.begin();
    int count=0;
    int Max=-1;
    while(iter!=s.end())
    {
        if(*iter=='A' || *iter=='E' || *iter=='I' ||*iter=='O' ||*iter=='U' ||*iter=='Y')
        {
            count++;
            Max=max(Max,count);
            count=0;
        }
        else
        {
            count++;
        }
        iter++;
    }
    iter--;
    if(*iter!='A'&&*iter!='E'&&*iter!='I'&&*iter!='O'&&*iter!='U'&&*iter!='Y')
        count++;
    Max=max(count,Max);
    cout<<Max<<endl;
    return 0;
}