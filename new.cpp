#include<bits/stdc++.h>
class Solution
{
public:
    int maxAmt(int n , int hi[] , int li[])
    {
        vector<vector<int>>dp(n, vector<int> (3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    dp[i][0] = hi[0];
                    dp[i][1] = li[0];
                    dp[i][2] = 0;
                    continue;
                }

                if (j == 0) {
                    dp[i][j] = dp[i - 1][2] + hi[i];
                    continue;
                }
                if (j == 1) {
                    dp[i][j] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + li[i];
                    continue;
                }
                if (j == 2) {
                    dp[i][j] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
                    continue;
                }
            }
        }
        int ans = INT_MIN;
        for (auto x : dp[n - 1]) {
            ans = max(ans, x);
        }
        return ans;
    }
};