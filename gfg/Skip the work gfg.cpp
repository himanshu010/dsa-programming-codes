#include <bits/stdc++.h>

class Solution
{
  public:
    int minAmount(int A[], int N)
    {
        vector<pair<int, int>> dp(N);
        dp[0] = {A[0], 0};

        for (int i = 1; i < N; i++)
        {
            dp[i].first = min(dp[i - 1].first, dp[i - 1].second) + A[i];
            dp[i].second = dp[i - 1].first;
        }

        return min(dp[N - 1].first, dp[N - 1].second);
    }
};