int cutRod(int price[], int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + price[i - j - 1]);
        }
    }
    return dp[n];
}