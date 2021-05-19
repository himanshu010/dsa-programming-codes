class Solution
{
  public:
    int zigzagSequence(int n, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = M[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int mx = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k != j)
                    {
                        mx = max(mx, dp[i + 1][k]);
                    }
                }

                dp[i][j] = mx + M[i][j];
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, dp[0][i]);
        }

        return mx;
    }
};