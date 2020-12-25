#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int make_change(int *coins, int money, int n)
{
    int ans = 0;
    while (money > 0)
    {
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        cout << money << " - " << coins[idx];
        money -= coins[idx];
        cout << " = " << money << endl;
        ans++;
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
        int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        n = sizeof(coins) / sizeo f(int);
        int money;
        cin >> money;
        ans = make_change(coins, money, n);
        cout << "coins = " << ans;
    }
}