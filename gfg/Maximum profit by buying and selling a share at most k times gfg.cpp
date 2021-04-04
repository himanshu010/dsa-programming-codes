class Solution
{
  public:
    int maxProfit(int K, int N, int A[])
    {
        vector<vector<int>> dp(K + 1, vector<int>(N));
        for (int i = 0; i <= K; i++)
        {
            int mx = INT_MIN;
            for (int j = 0; j < N; j++)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    mx = max(dp[i - 1][j - 1] - A[j - 1], mx);
                    dp[i][j] = max(dp[i][j - 1], A[j] + mx);
                }
            }
        }
        return dp[K][N - 1];
    }
};