#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int getanswer(int n, int sum, int A[]) {
  for (int i = 0; i < n; ++i) {
    if (A[i] > 0) {
      return (i + 1);
      break;
    }
  }
  return (sum + 1);
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;cin>>t;while(t--)
  {
    int i, j, k, n, m, ans = -1, cnt = 0, sum = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    k = n - 1;
    j = 0;
    for (int i = 0; i < n; ++i) {

      if (A[i] <= 0 && k >= j) {
        int temp = A[i];

        A[i] = A[k];
        A[k] = temp;
        k--;
      }
      if (A[i] > 0) {
        int temp2 = A[i];
        A[i] = A[j];
        A[j] = temp2;
        j++;
      }
    }
    for (auto x : A) {
      if (x > 0) {
        sum++;
      }
    }
    for (int j = 0; j < sum; j++) {
      int temp = abs(A[j]);
      if (A[temp - 1] > 0) {
        A[temp - 1] = -A[temp - 1];
      }
    }
    ans = getanswer(n, sum, A);
    cout << ans;
  }
}