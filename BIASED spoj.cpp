#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define mkp make_pair

bool compare(pair<string, int> p1, pair<string, int> p2) {
  return (p1.S < p2.S);
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<pair<string, int>> asked_rank;
    for (int i = 0; i < n; ++i) {
      string name;
      int rank;
      cin >> name >> rank;
      asked_rank.pb(mkp(name, rank));
    }
    sort(asked_rank.begin(), asked_rank.end(), compare);
    int rank = 1;
    for (auto x : asked_rank) {
      sum += abs(x.S - rank);
      rank++;
    }
    cout << sum << endl;

    asked_rank.clear();
  }
}