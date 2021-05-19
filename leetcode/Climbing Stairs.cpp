class Solution
{
  public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int a = 0;
            if (i >= 2)
            {
                a = dp[i - 2];
            }
            dp[i] = a + dp[i - 1];
        }
        return dp[n];
    }
};