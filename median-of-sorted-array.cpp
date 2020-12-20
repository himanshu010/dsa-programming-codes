#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;cin>>t;while(t--)
  {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int A[n];
    int B[n];
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> B[i];
    }
    priority_queue<int, std::vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
      pq.push(A[i]);
      sum++;
    }
    for (int i = 0; i < n; i++) {
      pq.push(B[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
      pq.pop();
    }
    cout << pq.top();
  }
}