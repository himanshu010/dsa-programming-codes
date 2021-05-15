class Solution {
public:
	int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
	{
		if (N <= 1) {
			return 0;
		}
		sort(arr, arr + N);
		vector<int> dp(N);
		dp[0] = 0;
		dp[1] = arr[1] - arr[0] < K ? arr[1] + arr[0] : 0;
		for (int i = 2; i < N; i++) {
			dp[i] = (arr[i] - arr[i - 1]) < K ? max(arr[i] + arr[i - 1] + dp[i - 2], dp[i - 1]) : dp[i - 1];
		}
		return dp[N - 1];
	}
};