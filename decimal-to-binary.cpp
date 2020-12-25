#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int DecimaltoBinary(int n)
{
    int p = 1;
    int ans = 0;
    while (n)
    {
        int last_bit = n & 1;
        ans += last_bit * p;
        // cout<<ans<<endl;
        n = n >> 1;
        p *= 10;
    }
    return ans;
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        cout << DecimaltoBinary(n);
    }
}