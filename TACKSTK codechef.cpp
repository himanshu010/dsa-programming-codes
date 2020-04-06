#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mkp make_pair


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, d, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> d;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        i = 0
        while (i < n) {
            if (abs(a[i] - a[i + 1]) <= d) {
                ans++;
                i += 2;
            }
            else {
                i++;
            }
        }
        cout << ans;

    }
}