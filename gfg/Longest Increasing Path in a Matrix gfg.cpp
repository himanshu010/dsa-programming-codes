class Solution
{
  public:
    bool check(int r, int c, int n, int m)
    {
        return (r >= 0 and r < n and c >= 0 and c < m);
    }

    int findMax(vector<vector<int>> &a, int r, int c, vector<vector<int>> &dp, int n, int m)
    {

        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;
        if (check(r + 1, c, n, m) and a[r][c] > a[r + 1][c])
        {
            x = findMax(a, r + 1, c, dp, n, m);
        }
        if (check(r, c + 1, n, m) and a[r][c] > a[r][c + 1])
        {
            y = findMax(a, r, c + 1, dp, n, m);
        }
        if (check(r - 1, c, n, m) and a[r][c] > a[r - 1][c])
        {
            z = findMax(a, r - 1, c, dp, n, m);
        }
        if (check(r, c - 1, n, m) and a[r][c] > a[r][c - 1])
        {
            w = findMax(a, r, c - 1, dp, n, m);
        }

        return dp[r][c] = max({x, y, z, w, 0}) + 1;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] == -1)
                {
                    findMax(matrix, i, j, dp, n, m);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};