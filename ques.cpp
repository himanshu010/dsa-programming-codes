#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int ans(int i, priority_queue<int, std::vector<int>, greater<int>> pq, int a) {
  while (i--) {
    int b = pq.front();
    pq.pop();
    if (a[i] == b) {
      ans(i--);
    } else if (a[i] != b) {
      return 0;
      break;
    }
  }
  return 1;
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
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    priority_queue<int, std::vector<int>, greater<int>> pq;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
      pq.push_back(A[i]);
    }
    int ans = ans(n, pq, a[n]);
    if (ans == 1) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }
}