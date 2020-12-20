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

bool bfs(int **residualCapacity, int source, int sink, int n, int *parent) {
  bool visited[n];
  memset(visited, 0, sizeof(visited));

  queue<int> que;
  visited[source] = 1;
  que.push(source);

  bool foundAugumentedPath = false;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v = 0; v < n; ++v) {
      if (visited[v] == 0 and residualCapacity[u][v] > 0) {
        parent[v] = u;
        visited[v] = true;
        que.push(v);
        if (v == sink) {
          foundAugumentedPath = true;
          break;
        }
      }
    }
  }

  return foundAugumentedPath;
}

void printAugumentsPaths(vector<vector<int>> augumentedPaths) {
  for (int i = 0; i < augumentedPaths.size(); ++i) {
    for (int j = 0; j < augumentedPaths[i].size(); ++j) {
      cout << augumentedPaths[i][j] << ", ";
    }
    cout << endl;
  }
}

int maxFlow(int **capacity, int source, int sink, int v) {
  int **residualCapacity = new int *[v];
  for (int i = 0; i < v; ++i) {
    residualCapacity[i] = new int[v];
  }

  for (int i = 0; i < v; ++i) {
    for (int j = 0; j < v; ++j) {
      residualCapacity[i][j] = capacity[i][j];
    }
  }

  int *parent = new int[1000];
  vector<vector<int>> augumentedPaths;

  int maxFlow = 0;

  while (bfs(residualCapacity, source, sink, v, parent)) {
    vector<int> currentAugumentedPath;
    int flow = INT_MAX;

    int v = sink;
    while (v != source) {
      currentAugumentedPath.pb(v);
      int u = parent[v];
      if (flow > residualCapacity[u][v]) {
        flow = residualCapacity[u][v];
      }
      v = u;
    }

    currentAugumentedPath.pb(source);
    augumentedPaths.pb(currentAugumentedPath);
    reverse(currentAugumentedPath.begin(), currentAugumentedPath.end());
    maxFlow += flow;

    v = sink;
    while (v != source) {
      int u = parent[v];
      residualCapacity[u][v] -= flow;
      residualCapacity[v][u] += flow;
      v = u;
    }
  }
  printAugumentsPaths(augumentedPaths);
  return maxFlow;
}

void solve() {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  int v, e;
  cin >> v >> e;

  int **capacity = new int *[v];

  for (int i = 0; i < v; ++i) {
    capacity[i] = new int[v];
  }

  for (int i = 0; i < e; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    capacity[x][y] = w;
  }
  cout << maxFlow(capacity, 0, 1, v);
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