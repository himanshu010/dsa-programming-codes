long long int maxProd(long long int n, vector<long long int> &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n == 1 or n == 0)
    {
        return 0;
    }
    long long int prod = 0;
    for (long long int i = 1; i < n; i++)
    {
        long long int aa = max((i * (n - i)) % 1000000007, (maxProd(n - i, dp) * i) % 1000000007);
        prod = max(aa, prod);
    }
    return dp[n] = prod % 1000000007;
}
long long int maxProduct(long long int n)
{
    vector<long long int> dp(n + 1, -1);
    return maxProd(n, dp);
}
