class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pre(n, 0), suff(n, 0);
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, prices[i]);
            pre[i] = max(pre[i], prices[i] - mn);
        }

        int mx = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, prices[i]);
            suff[i] = max(suff[i + 1], mx - prices[i]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i] + suff[i]);
        }
        return ans;
    }
};