class Solution {
public:

    int checkMax(vector<int> &piles, int s, int e, vector<vector<int>> &dp) {
        if (s > e) {
            return 0;
        }
        if (dp[s][e] != -1) {
            return dp[s][e];
        }

        if (s == e) {
            return piles[s];
        }
        return dp[s][e] = max(piles[s] + min(checkMax(piles, s + 2, e, dp), checkMax(piles, s + 1, e - 1, dp)), piles[e] + min(checkMax(piles, s + 1, e - 1, dp), checkMax(piles, s, e - 2, dp)));
    }

    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, -1));
        return accumulate(piles.begin(), piles.end(), 0) - 2 * checkMax(piles, 0, piles.size() - 1, dp) < 0;
    }
};