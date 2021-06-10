class Solution
{
  public:
    int minOperation(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int t = i % 2 == 0 ? dp[i / 2] : INT_MAX;
            dp[i] = min(t, dp[i - 1]) + 1;
        }
        return dp[n];
    }
};