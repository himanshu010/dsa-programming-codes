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
  void addEdge(int x, int y) { l[x].pb(y); }
  void topological_sort_bfs() {
    int *indegree = new int[V];
    for (int i = 0; i < V; ++i) {
      // cout << i << "-----" << endl;
      indegree[i] = 0;
    }
    // update indegree by traversing edges x->y
    // indegree[y]++

    for (int i = 0; i < V; i++) {
      for (auto y : l[i]) {
        indegree[y]++;
      }
    }

    // bfs
    queue<int> q;
    // 1. find node with 0 indegree
    for (int i = 0; i < V; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    // 2. start removing element from the queue
    while (!q.empty()) {
      int node = q.front();
      cout << node << " ";
      q.pop();
      // 3. iterate over the neighbour of that node
      for (auto nbr : l[node]) {
        indegree[nbr]--;
        if (indegree[nbr] == 0) {
          q.push(nbr);
        }
      }
    }
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
    int i, j, k, vertices, edges, ans = 0, cnt = 0, sum = 0;
    cin >> vertices;
    Graph g(vertices);
    cin >> edges;
    for (int i = 0; i < edges; ++i) {
      int a, b;
      cin >> a >> b;
      g.addEdge(a, b);
    }
    g.topological_sort_bfs();
  }
}