#include <iostream>
using namespace std;
int a[30];
int main()
{
    int n;
    while(cin>>n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 0; i < n; ++i)
            res ^= a[i];
        if (res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}