long long countWays(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int a = 0, b = 0;
        if (i - 3 >= 0)
        {
            a = dp[i - 3];
        }
        if (i - 2 >= 0)
        {
            b = dp[i - 2];
        }

        dp[i] = (((a + b) % moduli) + dp[i - 1]) % moduli;
    }

    return dp[n];
}