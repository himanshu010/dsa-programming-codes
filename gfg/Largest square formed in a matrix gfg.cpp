#include <bits/stdc++.h>
#define int long long int
using namespace std;
int solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        for (int i = 0; i < m; ++i)
        {
            if (a[0][i] == 1) {
                return 1;
            }
        }
        return 0;
    }
    if (m == 1) {
        for (int i = 0; i < n; ++i)
        {
            if (a[i][0] == 1) {
                return 1;
            }
        }
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        dp[0][i] = a[0][i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i][0];
    }
    int maximum = INT_MIN;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == 0) {
                dp[i][j] = 0;
            }
            else {
                int val = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                dp[i][j] = val + 1;
            }
            maximum = max(maximum, dp[i][j]);
        }
    }
    return maximum;
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t; while (t--) {
        cout << solve() << endl;
    }
    return 0;
}