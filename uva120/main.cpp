#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
int main()
{
	int n;
	while(~scanf("%d",&n)){
		int num;
			for(int i=1;i<=n;++i){
				scanf("%d",&num);
				A.push_back(num);
			}
			int MAX;
			int mark;
			int j;
			for(int i=n;i>=1;--i){
				MAX=A[i];
				for(j=i-1;j>=1;--j){
				if(A[j]>MAX){
					mark=j;
					MAX=A[j];
				}
			}
			vector<int>::iterator iter=A.begin(),iter1;
			iter1=iter;
			for(;iter1!=A.end();++iter1){
				cout<<*iter<<" ";
			}
			cout<<endl;
			A[i]=A[1];
			printf("%d ",j);
		}
		printf("0\n");
	}
}

