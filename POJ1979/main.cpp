#include<iostream>
using namespace std;
int m,n;
char map[30][30];
int ans=1;
void solve(int dx,int dy)
{
    map[dx][dy]='#';
	for(int i=-1;i<=1;++i){
	   for(int j=-1;j<=1;++j){
		   if(i==0 || j==0){
			   int x=dx+i;
			   int y=dy+j;
	         if(x>=0 && y>=0 && y<m && x<n && map[x][y]=='.'){
                 solve(x,y);
				 ans++;
			 }
		   }
	   }
	}
}
int main()
{
    while(cin>>m>>n) {
        if(m==0&&n==0)
            break;
        ans=1;
        int startx, starty;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> map[i][j];
                if (map[i][j] == '@') {
                    map[i][j] = '.';
                    startx = i;
                    starty = j;
                }
            }
        }
        solve(startx, starty);
        cout << ans << endl;
    }
}
