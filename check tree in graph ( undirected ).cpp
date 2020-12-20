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
  int V;

public:
  Graph(int V) {
    this->V = V;
    l = new list<int>[V];
  }
  void addEdge(int x, int y) {
    l[x].pb(y);
    l[y].pb(x);
  }
  bool is_tree() {
    bool *visited = new bool[V];
    int *parent = new int[V];
    queue<int> q;
    for (int i = 0; i < V; ++i) {
      visited[i] = false;
      parent[i] = i;
    }

    int src = 0;
    q.push(src);
    visited[src] = true;

    // pop out one node and visite its neighbour
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto nbr : l[node]) {
        if (visited[nbr] == true && parent[node] != nbr) {
          return false;
        } else if (!visited[nbr]) {
          visited[nbr] = true;
          parent[nbr] = node;
          q.push(nbr);
        }
      }
    }
    return true;
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
    int i, v, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> v >> n;
    Graph g(v);
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      g.addEdge(x, y);
    }
    if (g.is_tree()) {
      cout << "Yes it is a tree" << endl;
    } else {
      cout << "Not a tree, its cyclic" << endl;
    }
  }
}