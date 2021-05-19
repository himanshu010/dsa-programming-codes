class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++) {
            mn = min(mn, prices[i]);
            profit = max(profit, prices[i] - mn);
        }

        return profit;
    }
};