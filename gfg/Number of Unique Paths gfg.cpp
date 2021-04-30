class Solution
{
public:
	//Function to find total number of unique paths.
	int NumberOfPath(int a, int b)
	{
		vector<vector<int>>dp(a, vector<int>(b));
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (i == 0 or j == 0) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[a - 1][b - 1];
	}

};