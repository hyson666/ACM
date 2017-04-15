#include <iostream>
using namespace std;
int table[101];
int main() {
    /*
    int mark=3;
    int count=3;
    for(int i=3;i<=10010;++i){
        if((mark+i)%3==0 && (mark+i)%2==1) {
            table[i] = count%2;
            ++count;
            mark = i;
        }a
        else
            table[i]=2;
    }
    for(int i=1;i<=101;++i){
        cout<<"CASE "<<i<<":"<<table[i]<<endl;
    }
    return 0;
     */
    int q;
    int qnum=1;
    cin>>q;
    while(q--){
        int num;
        scanf("%d",&num);
        int ans=0;
        int temp;
        for(int i=1;i<=num;++i){
            scanf("%d",&temp);
            if(i%6==0 || i%6==2 || i%6==5)
                ans^=temp;
        }
        if(ans) printf("Case %d: %s\n",qnum,"Alice");
        else printf("Case %d: %s\n",qnum,"Bob");
        qnum++;
    }
    return 0;
}