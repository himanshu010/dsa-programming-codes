/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|                       (himanshu010)                       |
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

class Graph {
  list<int> *l;
  int v;

public:
  Graph(int v) {
    this->v = v;
    l = new list<int>[v];
  }
  void addEdge(int x, int y) { l[x].pb(y); }

  bool cycle_helper(int node, bool *visited, bool *stack) {
    // visit a node
    visited[node] = true;
    stack[node] = true;

    for (auto nbr : l[node]) {
      if (stack[nbr]) {
        return true;
      }
      if (visited[nbr] == false) {
        bool cycle_present = cycle_helper(nbr, visited, stack);
        if (cycle_present == true) {
          return true;
        }
      }
    }

    // leave a node
    stack[node] = false;
    R false;
  }
  bool contains_cycle() {
    bool *visited = new bool[v];
    bool *stack = new bool[v];

    for (int i = 0; i < v; ++i) {
      visited[i] = stack[i] = false;
    }
    return cycle_helper(0, visited, stack);
  }
};

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
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
      cin >> k >> j;
      g.addEdge(k, j);
    }
    if (g.contains_cycle()) {
      cout << "Not a tree, its cyclic" << endl;
    } else {
      cout << "Yes it is a tree" << endl;
    }
  }
}