class Solution
{
  public:
    long long coinChange(vector<int> &coins, int amount)
    {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto x : coins)
        {
            if (x <= amount)
            {
                dp[x] = 1;
            }
        }

        for (long long i = 1; i <= amount; i++)
        {
            for (auto x : coins)
            {
                if (i - x >= 0)
                {
                    dp[i] = min(dp[i], dp[i - x] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};