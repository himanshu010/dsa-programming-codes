long long countWays(int N)
{
    vector<long long> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        long long a = 0, b = 0;
        if (i - 4 >= 0)
        {
            a = dp[i - 4];
        }
        if (i - 3 >= 0)
        {
            b = dp[i - 3];
        }
        dp[i] = (((a + b) % moduli) + dp[i - 1]) % moduli;
    }
    return dp[N];
}