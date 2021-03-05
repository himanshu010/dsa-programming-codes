#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define LOCAL
#define MOD 1000000007

//
// author: Rawnix
//

int32_t main()
{
    // #ifdef LOCAL
    //     freopen("in05.txt", "r", stdin);
    //     freopen("out05.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    assert(n <= 100000 && n >= 1);
    assert(l < n && l >= 0);
    vector<int> ladders(n, -1);
    vector<pair<int, int>> lad;
    vector<bool> ended(n + 1, false);
    for (int i = 0; i < l; i++)
    {
        int a, b;
        cin >> a >> b;
        lad.push_back({a, b});
        if (ladders[a] != -1)
        {
            return -1;
        }
        ladders[a] = b;
        ended[b] = true;
        if (ended[a])
        {
            return -1;
        }
    }
    vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
    dp1[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (ladders[i] != -1)
        {
            dp1[ladders[i]] = (dp1[ladders[i]] + dp1[i]) % MOD;
        }
        else
        {
            for (int j = 1; j <= 6; j++)
            {
                if (i + j <= n)
                {
                    dp1[i + j] = (dp1[i + j] + dp1[i]) % MOD;
                }
            }
        }
    }
    dp2[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ladders[i] != -1)
        {
            dp2[i] = dp2[ladders[i]];
        }
        else
        {
            for (int j = 6; j >= 1; j--)
            {
                if (i + j <= n)
                {
                    dp2[i] = (dp2[i] + dp2[i + j]) % MOD;
                }
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        cout << (dp1[lad[i].first] * dp2[lad[i].second]) % MOD << endl;
    }
    return 0;
}