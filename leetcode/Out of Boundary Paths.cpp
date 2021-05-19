#define mod 1000000007
class Solution
{
  public:
    vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int dfs(int n, int m, int r, int c, int t, vector<vector<vector<int>>> &dp)
    {
        if (t < 0)
        {
            return 0;
        }
        if (r < 0 or c < 0 or r >= n or c >= m)
        {
            return 1;
        }
        if (t == 0)
        {
            return 0;
        }
        if (dp[r][c][t] != -1)
        {
            return dp[r][c][t];
        }
        int sum = 0;
        for (auto x : moves)
        {
            sum = (sum + dfs(n, m, r + x.first, c + x.second, t - 1, dp)) % mod;
        }
        return dp[r][c][t] = sum;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        return dfs(m, n, startRow, startColumn, maxMove, dp);
    }
};