class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int a = INT_MIN, b = INT_MIN, c = INT_MIN;
            if (i - x >= 0) {
                a = dp[i - x];
            }
            if (i - y >= 0) {
                b = dp[i - y];
            }
            if (i - z >= 0) {
                c = dp[i - z];
            }


            dp[i] = max({a, b, c}) == INT_MIN ? INT_MIN : max({a, b, c}) + 1;
        }
        return dp[n] == INT_MIN ? 0 : dp[n];
    }
};