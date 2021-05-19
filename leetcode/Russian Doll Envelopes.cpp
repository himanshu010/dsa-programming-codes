class Solution {
public:
	static bool compare(vector<int> a, vector<int> b) {
		return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
	}
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		int n = envelopes.size();
		sort(envelopes.begin(), envelopes.end(), compare);
		vector<int>dp(n);
		dp[0] = 1;
		int ans = 1;
		for (int i = 1; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < i; j++) {
				if (envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1]) {
					temp = max(temp, dp[j]);
				}
			}
			dp[i] = temp + 1;
			ans = max(dp[i], ans);
		}

		return ans;
	}
};