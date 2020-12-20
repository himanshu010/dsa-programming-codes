/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
*-----------------------------------------------------------*

*/

#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map

using namespace std;

const int N = 100005;

vector<int> tree(N, INT_MAX);
vector<int> lazy(N, 0);

void buildtree(int *a, int start, int end, int index) {
  if (start == end) {
    tree[index] = a[start];
    return;
  }

  int mid = (start + end) / 2;

  buildtree(a, start, mid, 2 * index);
  buildtree(a, mid + 1, end, 2 * index + 1);

  tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query(int node_start, int node_end, int query_start, int query_end,
          int index) {
  if (query_end < node_start or query_start > node_end) {
    return INT_MAX;
  }

  if (query_start <= node_start and query_end >= node_end) {
    return tree[index];
  }

  int mid = (node_start + node_end) / 2;

  int left = query(node_start, mid, query_start, query_end, 2 * index);
  int right = query(mid + 1, node_end, query_start, query_end, 2 * index + 1);

  return min(left, right);
}

void updateRangeLAZY(int node_start, int node_end, int update_start,
                     int update_end, int update_value, int index) {
  if (lazy[index] != 0) {
    tree[index] += lazy[index];

    if (node_start != node_end) {
      lazy[2 * index] += lazy[index];
      lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
  }

  if (update_start > node_end or update_end < node_start) {
    return;
  }

  if (update_start <= node_start and update_end >= node_end) {
    tree[index] += update_value;
    if (node_start != node_end) {

      lazy[2 * index] += update_value;
      lazy[2 * index + 1] += update_value;
    }
    return;
  }

  int mid = (node_start + node_end) / 2;

  updateRangeLAZY(node_start, mid, update_start, update_end, update_value,
                  2 * index);

  updateRangeLAZY(mid + 1, node_end, update_start, update_end, update_value,
                  2 * index + 1);

  tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int queryLAZY(int node_start, int node_end, int query_start, int query_end,
              int index) {
  if (lazy[index] != 0) {
    tree[index] += lazy[index];
    if (node_start != node_end) {
      lazy[2 * index] += lazy[index];
      lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
  }

  if (query_end < node_start or query_start > node_end) {
    return INT_MAX;
  }

  if (query_start <= node_start and query_end >= node_end) {
    return tree[index];
  }

  int mid = (node_start + node_end) / 2;
  int left = queryLAZY(node_start, mid, query_start, query_end, 2 * index);
  int right =
      queryLAZY(mid + 1, node_end, query_start, query_end, 2 * index + 1);

  return min(left, right);
}

void solve(int tc) {
  int i, j, k, n, q, m, ans = 0, cnt = 0, sum = 0;

  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  buildtree(a, 0, n - 1, 1);

  updateRangeLAZY(0, n - 1, 3, 5, 5, 1);

  cin >> q;
  while (q--) {
    int l, r;

    cin >> l >> r;
    cout << queryLAZY(0, n - 1, l, r, 1) << endl;
  }
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
    int tc = 1;
    solve(tc);
    tc++;
  }
}