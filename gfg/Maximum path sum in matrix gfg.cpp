class Solution
{
  public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            dp[N - 1][i] = Matrix[N - 1][i];
        }
        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = 0; j < N; j++)
            {
                int a = 0, b = 0, c = 0;
                if (j - 1 >= 0)
                {
                    a = dp[i + 1][j - 1];
                }
                b = dp[i + 1][j];
                if (j + 1 < N)
                {
                    c = dp[i + 1][j + 1];
                }

                dp[i][j] = max(a, max(b, c)) + Matrix[i][j];
            }
        }
        int ans = INT_MIN;
        for (auto x : dp[0])
        {
            ans = max(ans, x);
        }

        return ans;
    }
};