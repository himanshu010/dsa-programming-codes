#define mod 1000000007
class Solution
{
  public:
    long long countWays(int n, int k)
    {
        vector<vector<long long>> dp(3, vector<long long>(n));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    dp[2][j] = k;
                    continue;
                }
                if (j == 1)
                {
                    dp[0][j] = k;
                    dp[1][j] = (k * (k - 1)) % mod;
                    dp[2][j] = (dp[0][j] + dp[1][j]) % mod;
                    continue;
                }
                dp[0][j] = dp[1][j - 1];
                dp[1][j] = (dp[2][j - 1] * (k - 1)) % mod;
                dp[2][j] = (dp[0][j] + dp[1][j]) % mod;
            }
        }
        return dp[2][n - 1];
    }
};