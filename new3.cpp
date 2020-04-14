#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            cout << 1 << " " << 1 << endl;
            continue;
        }
        cout << n / 2 << endl;
        if (n % 2 == 0) {
            int k = 1;
            while (k < n) {
                printf("%d %d %d\n", 2, k, k + 1);
                //cout<<2<<" "<<k<<" "<<k+1<<endl;
                k += 2;
            }
        } else {
            cout << 3 << " " << 1 << " " << 2 << " " << n << endl;
            int k = 3;
            while (k < n) {
                printf("%d %d %d\n", 2, k, k + 1);
                //cout<<2<<' '<<k<<' '<<k+1<<endl;
                k += 2;
            }
        }
    }
    return 0;
}