class Solution
{
  public:
    bool checkString(string s1, string s2, string s3, int i, int j, int k, int n, int m, int o,
                     vector<vector<vector<int>>> &dp)
    {
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        if (i == n and j == m and k == o)
        {
            return 1;
        }
        if (k == o)
        {
            return 0;
        }
        bool ans = 0;
        if (s1[i] == s3[k])
        {
            ans |= checkString(s1, s2, s3, i + 1, j, k + 1, n, m, o, dp);
        }
        if (s2[j] == s3[k])
        {
            ans |= checkString(s1, s2, s3, i, j + 1, k + 1, n, m, o, dp);
        }
        return dp[i][j][k] = ans;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size(), o = s3.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(o + 1, -1)));
        return checkString(s1, s2, s3, 0, 0, 0, n, m, o, dp);
    }
};