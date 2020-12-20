int maxLen(int arr[], int n) {
  int maximum = 0;
  unordered_map<int, int> mp;
  vector<int> sums(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      sum += 1;
    } else {
      sum -= 1;
    }

    sums[i] = sum;
  }

  for (int i = 0; i < n; i++) {
    sum = sums[i];
    if (sum == 0) {

      maximum = max(maximum, i + 1);
    } else {
      if (mp.find(sum) != mp.end()) {
        // cout << sum << ' ' << i - mp[sum] << endl;
        maximum = max(maximum, i - mp[sum]);
      } else {
        //   cout<<"XXXXX"<<endl;
        mp[sum] = i;
      }
    }
  }

  return maximum;
}
