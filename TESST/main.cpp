#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
int main()
{
	int n;
	while(~scanf("%d",&n)) {
        int num;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &num);
            A.push_back(num);
        }
        int MAX;
        int mark;
        int j;
        for (int i = n - 1; i > 1; --i) {
            MAX = A[i];
            mark=i;
            for (j = i - 1; j >= 0; --j) {
                if (A[j] > MAX) {
                    mark = j;
                    MAX = A[j];
                }
            }
            if(mark!=1){
                vector<int>::iterator iter=A.begin();
                reverse(iter+n-mark-1,iter+n);
                printf("%d",n-mark-1);
            }
            else
                printf("%d ",i);
        }
        printf("0\n");
    }
}

