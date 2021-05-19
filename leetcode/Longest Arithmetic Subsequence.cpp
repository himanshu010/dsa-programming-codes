class Solution
{
  public:
    int longestArithSeqLength(vector<int> &a)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = a.size();
        int dp[n][2000];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2000; j++)
            {
                dp[i][j] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i][a[i] - a[j] + 1000] = max(dp[j][a[i] - a[j] + 1000] + 1, dp[i][a[i] - a[j] + 1000]);
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2000; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};