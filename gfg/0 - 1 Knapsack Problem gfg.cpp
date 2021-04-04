class Solution
{
  public:
    int getMax(int w, int wt[], int val[], int n, int sum)
    {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (j >= wt[i - 1])
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][w];
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        return getMax(W, wt, val, n, 0);
    }
};