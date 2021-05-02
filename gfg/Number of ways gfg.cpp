class Solution
{
  public:
    long long arrangeTiles(int N)
    {
        vector<long long int> dp(N + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            dp[i] = dp[i - 1];
            if (i - 4 >= 0)
            {
                dp[i] += dp[i - 4];
            }
        }
        return dp[N];
    }
};