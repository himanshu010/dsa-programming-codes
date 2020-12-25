#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int res = 1;

int fastMod(int a, int b, int m)
{
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return res;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int a, b, m, ans = 0, cnt = 0, sum = 0;
        cin >> a >> b >> m;
        ans = fastMod(a, b, m);
        cout << ans;
    }
}