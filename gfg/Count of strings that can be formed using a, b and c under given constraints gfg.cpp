long long findWays(int n, int b, int c, vector<vector<vector<int>>> &dp)
{
    if (b < 0 or c < 0)
    {
        return 0;
    }
    if (b == 0 and c == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 1;
    }

    if (dp[n][b][c] != -1)
    {
        return dp[n][b][c];
    }

    return dp[n][b][c] = (findWays(n - 1, b, c, dp) + findWays(n - 1, b - 1, c, dp) + findWays(n - 1, b, c - 1, dp));
}

long long int countStr(long long int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return findWays(n, 1, 2, dp);
}