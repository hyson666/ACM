#include<iostream>
using namespace std;
char map[110][110];
int m,n;
void solve(int dx,int dy)
{
    map[dx][dy]='.';
    for(int i=-1;i<=1;++i){
       for(int j=-1;j<=1;++j){
          int x=dx+i;
          int y=dy+j;
          if(x<0 || y<0 ||x>=m ||y>=m)
              continue;
          else if(map[x][y]=='W')
              solve(x,y);
       }
    }
   return;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
		   cin>>map[i][j];
	   }
	}
    int ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
             if(map[i][j]=='W'){
                solve(i,j);
			    ans++;
			 }
		}
	}
    cout<<ans<<endl;
}
