#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

// a INDEXING : 1 BASED
// tree INDEXING : 1 BASED
int a[100000];
int tree[100000] = {0};

void update(int index, int value, int n) {
  while (index <= n) {
    tree[index] += value;
    index += (index & (-index));
  }
}

int query(int index) {
  int ans = 0;
  while (index > 0) {
    ans += tree[index];
    index -= (index & (-index));
  }
  return ans;
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
    int i, j, k, n, no_of_query, left, right, m, ans = 0, cnt = 0, sum = 0;

    // BUILD AND UPDATE
    {
      cin >> n;

      for (int i = 1; i <= n; ++i) {
        cin >> a[i];
      }

      int ans = 0;
      for (int i = n; i >= 1; i--) {
        // cout << ans << "------>";
        ans += query(a[i] - 1);
        // cout << ans << endl;

        // cout << endl;

        update(a[i], 1, n);
      }
      cout << ans << "---" << endl;
    }

    int tree[100000] = {0};

    // //QUERY
    // {
    //     cin >> no_of_query;
    //     while (no_of_query--) {
    //         cin >> left >> right;

    //         //QUERY(index-to-query)
    //         cout << query(right) - query(left - 1) << endl;
    //     }
    // }
  }
}