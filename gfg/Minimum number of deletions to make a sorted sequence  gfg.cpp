class Solution {
public:
    int minDeletions(int arr[], int n)
    {
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    mx = max(mx, dp[j]);
            }
            dp[i] = mx + 1;
            ans = max(ans, dp[i]);
        }
        return n - ans;
    }
};