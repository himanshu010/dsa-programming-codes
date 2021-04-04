#include <bits/stdc++.h>
using namespace std;

int findAllWays(int n, int m)
{
    if (n < m)
    {
        return 1;
    }
    vector<int> dp(n + 1);
    for (int i = 0; i < m; ++i)
    {
        dp[i] = 1;
    }
    for (int i = m; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - m];
    }

    // if (n - 2 < 0) {
    //     return 1;
    // }

    // return findAllWays(n-1)+findAllWays(n-2);
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n;
    // if (n > m) {
    //     swap(n, m);
    // }
    cout << n << endl;
}