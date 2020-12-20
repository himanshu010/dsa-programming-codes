#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define mkp make_pair
#define MAX INT_MAX

template <typename T> class Graph {
  map<T, list<T>> adjList;

public:
  Graph() {}
  void addEdge(T u, T v, bool bidir = false) {
    adjList[u].push_back(v);
    if (bidir) {
      adjList[v].push_back(u);
    }
  }
  void print() {
    for (auto i : adjList) {
      cout << i.F << " ---> ";
      for (auto entry : i.S) {
        cout << entry << ",";
      }
      cout << endl;
    }
  }
  void bfs(T src) {
    queue<T> q;
    map<T, bool> visited;

    q.push(src);
    visited[src] = 1;

    while (!q.empty()) {
      T node = q.front();
      cout << node << " ";
      q.pop();

      // for neighbour of current node
      for (auto neighbour : adjList[node]) {
        if (!visited[neighbour]) {
          q.push(neighbour);
          visited[neighbour] = 1;
        }
      }
    }
  }
  void sssp(T src) {
    queue<T> q;
    map<T, int> dist;
    map<T, T> parent;
    int ans;

    for (auto i : adjList) {
      dist[i.F] = MAX;
    }

    q.push(src);
    dist[src] = 0;
    parent[src] = src;

    while (!q.empty()) {
      T node = q.front();
      q.pop();

      // for neighbour of current node
      for (auto neighbour : adjList[node]) {
        if (dist[neighbour] == INT_MAX) {
          q.push(neighbour);
          dist[neighbour] = dist[node] + 1;
          parent[neighbour] = node;
        }
      }
    }
    // Print the distance to all node
    for (auto i : adjList) {
      T node = i.first;
      cout << "Dist of " << node << " is " << dist[node] << endl;
    }
  }
  // recursive function that will traverse the graph
  void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
    cout << src << " ";
    visited[src] = true;

    // go to all neighbour of that node that is not visited
    for (auto neighbour : adjList[src]) {
      if (!visited[neighbour]) {
        dfs_helper(neighbour, visited, ordering);
      }
    }
    ordering.push_front(src);
  }

  void dfs(T src) {
    map<T, bool> visited;
    list<T> ordering;
    // mark all the nodes as not visited in the beginning
    for (auto node_pair : adjList) {
      T node = node_pair.F;
      visited[node] = false;
    }

    // call the helper function
    // dfs_helper(src,  visited);

    // for Non-Connected components
    // iterate over all the vertices and init the dfs call
    {
      int cnt = 1;
      for (auto node_pair : adjList) {
        T node = node_pair.F;

        if (!visited[node]) {
          cout << "Component " << cnt << " -->";
          dfs_helper(node, visited, ordering);
          cnt++;
          cout << endl;
        }
      }
    }
    // finally print the list
    for (auto node : ordering) {
      cout << node << endl;
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
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    Graph<string> g;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      string l, r;
      w bool bidir;
      cin >> l >> r;
      g.addEdge(l, r);
    }
    g.print();
    // g.bfs(0);
    g.dfs("python");
  }
}