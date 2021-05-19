class Solution
{
  public:
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }

    int videoStitching(vector<vector<int>> &clips, int T)
    {
        if (T == 0)
        {
            return 0;
        }
        int n = clips.size();
        vector<pair<int, int>> se(n);
        vector<int> dp(n, INT_MAX);
        sort(clips.begin(), clips.end(), compare);

        se[0] = {clips[0][0], clips[0][1]};
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int s = clips[i][0];
            int e = clips[i][1];
            if (s == 0)
            {
                dp[i] = 1;
                se[i] = {s, e};
                continue;
            }
            int cost = INT_MAX;
            for (int j = 0; j < i; j++)
            {
                if (se[j].first == 0 and cost > dp[j] and se[j].second >= s)
                {
                    cost = dp[j];
                    s = 0;
                }
            }
            if (cost != INT_MAX)
                dp[i] = cost + 1;
            se[i] = {s, e};
        }
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (se[i].first == 0 and se[i].second >= T)
            {
                ans = min(ans, dp[i]);
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};