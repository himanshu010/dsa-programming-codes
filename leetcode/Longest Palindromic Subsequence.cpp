class Solution
{
  public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int i = 0, j = 0, k = 0;
        while (j - i < n)
        {
            while (j < n)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (i == j - 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }

                else if (j - i >= 2)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
                i++;
                j++;
            }
            i = 0;
            j = k + 1;
            k += 1;
        }

        return dp[0][n - 1];
    }
};