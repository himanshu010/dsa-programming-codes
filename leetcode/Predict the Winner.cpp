class Solution
{
  public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums)
        {
            sum += x;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int k = 1;
        while (j - i <= n - 1)
        {
            while (j < n)
            {
                if (i == j)
                {
                    dp[i][j] = nums[i];
                }
                else if (i + 1 == j)
                {
                    dp[i][j] = max(nums[i], nums[j]);
                }
                else
                {
                    dp[i][j] = max(nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                                   nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
                }
                i++;
                j++;
            }
            i = 0;
            j = i + k;
            k += 1;
        }

        return dp[0][n - 1] >= sum - dp[0][n - 1];
    }
};