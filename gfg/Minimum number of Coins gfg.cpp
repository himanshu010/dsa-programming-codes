class Solution
{
  public:
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> minPartition(int N)
    {
        vector<pair<int, int>> dp(N + 1);
        dp[0] = {0, 0};
        for (int i = 1; i <= N; i++)
        {
            int mn = INT_MAX;
            int last;
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                {
                    if (dp[i - coins[j]].first < mn)
                    {
                        mn = dp[i - coins[j]].first;
                        last = i - coins[j];
                    }
                }
            }

            dp[i] = {mn + 1, last};
        }
        vector<int> ans;
        pair<int, int> cur = dp[N];
        while (cur.first != 0)
        {
            ans.push_back(N - cur.second);
            N = cur.second;
            cur = dp[cur.second];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};