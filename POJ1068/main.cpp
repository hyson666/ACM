#include <iostream>
#include <cstring>
using namespace std;
int p[10001],w[10001];
int book[10001];
char s[10001];
int main() {
     int n;
     cin>>n;
     while(n--)
     {
         memset(book,0,sizeof(book));
         int num;
         cin>>num;
         for(int i=1;i<=num;++i)
             cin>>p[i];
         for(int i=0;i<=num;++i)
             w[i]=0;
         int count=0;
         int note=0;
         for(int i=1;i<=num;++i)
         {
             int t=count;
             for(int j=0;j<p[i]-t;++j)
             {
                 s[note]='(';
                 note++;
                 count++;
             }
             s[note]=')';
             note++;
         }
         s[note]=0;
         count=0;
         int flag=0;
         while(s[count]!=0)
         {
             if(s[count]==')')
             {
                 int tag=count-1;
                 while(tag>=0)
                 {
                     if(s[tag]=='(' && book[tag]==0) {
                         book[tag] = 1;
                         w[flag]++;
                         break;
                     }
                     if(s[tag]=='(' )
                         w[flag]++;
                     tag--;
                 }
                 flag++;
             }
             count++;
         }
         for(int i=0;i<num;++i)
         {
             cout<<w[i]<<" ";
         }
         cout<<endl;
     }
    return 0;
}