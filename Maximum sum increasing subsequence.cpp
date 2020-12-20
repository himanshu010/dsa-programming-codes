class Solution {
public:
  int maxSumIS(int arr[], int n) {
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i] and dp[i] < dp[j] + arr[i]) {
          dp[i] = dp[j] + arr[i];
        }
      }
    }
    int maximum = INT_MIN;
    for (auto x : dp) {
      maximum = max(x, maximum);
    }
    return maximum;
  }
};
