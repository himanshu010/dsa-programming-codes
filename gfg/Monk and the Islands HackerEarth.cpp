// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/submissions/

#include<bits/stdc++.h>
#define pb push_back

using namespace std;
vector<vector<int>> graph(10001);
vector<int> visited(10001, -1);

void addEdge(int l, int r) {
  graph[l].pb(r);
  graph[r].pb(l);
}

void bfs(int src, int n) {
  queue<int> qu;
  visited[src] = 0;
  qu.push(src);
  while (!qu.empty()) {
    int cur = qu.front();
    if (cur == n) {
      cout << visited[cur] << endl;
      return;
    }
    qu.pop();
    for (auto x : graph[cur]) {
      if (visited[x] == -1) {
        qu.push(x);
        visited[x] = 1 + visited[cur];
      }
    }
  }
  cout << visited[n] << endl;
  return;
}

void solve() {
  graph.clear(); graph.resize(10001);
  visited.clear(); visited.resize(10001);
  fill(visited.begin(), visited.end(), -1);
  int n, m;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    addEdge(l, r);
  }

  bfs(1, n);
}


int main() {
  int t; cin >> t; while (t--) {
    solve();
  }
}