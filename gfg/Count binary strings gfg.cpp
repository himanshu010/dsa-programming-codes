#define mod 1000000007

class Solution
{
  public:
    int countStrings(int n, int k)
    {
        vector<vector<vector<long long int>>> dp(2, vector<vector<long long int>>(n + 1, vector<long long int>(k + 1)));
        dp[0][1][0] = 1;
        dp[1][1][0] = 1;

        for (long long int i = 2; i <= n; i++)
        {
            for (long long int j = 0; j <= k; j++)
            {
                dp[0][i][j] = (dp[0][i - 1][j] + dp[1][i - 1][j]) % mod;
                dp[1][i][j] = dp[0][i - 1][j] % mod;
                if (j - 1 >= 0)
                {
                    dp[1][i][j] += (dp[1][i - 1][j - 1]) % mod;
                }
            }
        }

        return (dp[0][n][k] + dp[1][n][k]) % mod;
    }
};