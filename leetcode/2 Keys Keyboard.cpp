class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            // cout<<i<<'-';
            for (int j = 1; j <= n / 2; j++) {
                if (i % j == 0) {
                    // cout<<j<<' ';
                    dp[i] = min(dp[i], dp[j] + (i / j));
                }
            }
            // cout<<endl;
        }

        return dp[n];
    }
};