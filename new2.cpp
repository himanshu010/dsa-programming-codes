class Solution
{
  public:
    int countWays(string a, string b)
    {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m));

        for (int i = 0; i < m; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i - 1] == b[j])
                {
                    if (j == 0)
                    {
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m - 1];
    }
};