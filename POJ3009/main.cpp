#include<iostream>
using namespace std;
#define inf 99999999
int xx[5]={0,-1,0,1,0}, yy[5]={0,0,1,0,-1};
int map[25][25];
int ans=0;
int w,h;
void solve(int x,int y,int count)
{
	int nx=x,ny=y;
	if(count>10)
		return;
    for(int i=1;i<=4;++i){
		nx=x;
		ny=y;
		if(map[nx+xx[i]][ny+yy[i]]==1)
			continue;
		while(nx>=0 && ny>=0 && nx<h && ny<w){
			if(map[nx][ny]==3) {
				ans = min(ans, count);
				return;
			}
			if(map[nx][ny]==1){
				break;
			}
			nx+=xx[i];
			ny+=yy[i];
		}
		if(nx<0 || ny<0 || nx>=h || ny>=w )
			continue;
		map[nx][ny]=0;
		solve(nx-xx[i],ny-yy[i],count+1);
		map[nx][ny]=1;
	}

}
int main()
{
    while(cin>>w>>h){
	   if(w==0&&h==0)
		   break;
	   ans=inf;
	   int startx,starty;
	   for(int i=0;i<h;++i){
	      for(int j=0;j<w;++j){
		      scanf("%d",&map[i][j]);
			  if(map[i][j]==2){
				  startx=i;
				  starty=j;
			      map[i][j]=0;
			  }
		  }
	   }
       solve(startx,starty,1);
		if(ans==inf)
			cout<<-1<<endl;
		else
	        printf("%d\n",ans);
	}
}
