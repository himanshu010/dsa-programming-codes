class Solution
{
  public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int mx = INT_MAX;
        int n = matrix.size();
        if (n == 1)
        {
            for (auto x : matrix[0])
            {
                mx = min(mx, x);
            }
            return mx;
        }
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp[1][i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if ((n & 1 and i & 1) or (n % 2 == 0 and i % 2 == 0))
                {
                    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
                    if (j - 1 >= 0)
                    {
                        a = dp[1][j - 1];
                    }
                    b = dp[1][j];
                    if (j + 1 < n)
                    {
                        c = dp[1][j + 1];
                    }
                    dp[0][j] = min(a, min(b, c)) + matrix[i][j];
                }
                else
                {
                    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
                    if (j - 1 >= 0)
                    {
                        a = dp[0][j - 1];
                    }
                    b = dp[0][j];
                    if (j + 1 < n)
                    {
                        c = dp[0][j + 1];
                    }
                    dp[1][j] = min(a, min(b, c)) + matrix[i][j];
                }
            }
        }

        for (auto x : dp[n & 1])
        {
            mx = min(x, mx);
        }
        return mx;
    }
};