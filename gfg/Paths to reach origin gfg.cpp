#define mod 1000000007

class Solution
{
  public:
    int dfs(int x, int y, vector<vector<int>> &dp)
    {
        if (x < 0 or y < 0)
        {
            return 0;
        }
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        if (x == 0 and y == 0)
        {
            return 1;
        }

        return dp[x][y] = (dfs(x - 1, y, dp) + dfs(x, y - 1, dp)) % mod;
    }
    int ways(int x, int y)
    {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return dfs(x, y, dp);
    }
};