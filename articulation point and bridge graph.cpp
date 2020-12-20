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
#define R return

using namespace std;

const int N = 100005, M = 22;

vector<int> gr[N];
set<int> art_p;
vector<P> bridge;

int disc[N], low[N], tme;

void dfs(int cur, int par) {
  disc[cur] = low[cur] = tme++;
  int no_child = 0;
  for (auto child : gr[cur]) {
    if (disc[child] == 0) {
      dfs(child, cur);
      no_child++;
      low[cur] = min(low[cur], low[child]);

      // art point

      if (par != 0 && low[child] >= disc[cur]) {
        art_p.insert(cur);
      }

      // bridge

      if (low[child] > disc[cur]) {
        bridge.pb({cur, child});
      }
    } else if (child != par) {
      // backedge
      // cycle found
      low[cur] = min(low[cur], disc[child]);
    }
  }
  if (par == 0 and no_child >= 2) {
    art_p.insert(cur);
  }
  return;
}

void solve() {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    gr[x].pb(y);
    gr[y].pb(x);
  }

  tme = 1;
  dfs(1, 0);
  for (auto x : art_p) {
    cout << x << " ";
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
  { solve(); }
}