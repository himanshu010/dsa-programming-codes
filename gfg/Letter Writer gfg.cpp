class Solution {
public:
    int minHours(int N) {
        vector<int>dp(N + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            int mn = INT_MAX;
            if (i - 10 >= 0) {
                mn = min(mn, dp[i - 10]);
            }
            if (i - 12 >= 0) {
                mn = min(mn, dp[i - 12]);
            }

            if (mn == INT_MAX) {
                continue;
            }

            dp[i] = mn + 1;
        }

        return dp[N] == INT_MAX ? -1 : dp[N];
    }
};