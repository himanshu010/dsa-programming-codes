vector<vector<int>>graph(100005);
vector<bool> visited(100005, 0);

void addEdge(int l, int r) {
  graph[l - 1].pb(r - 1);
}

int ans = 0;
int dfs(int src) {

  visited[src] = 1;

  if (graph[src].size() == 0) {
    return 1;
  }
  int cnt = 0;
  for (auto child : graph[src]) {
    if (!visited[child]) {
      cnt += dfs(child);
    }
  }
  if ((cnt + 1) % 2 == 0) {
    ans++;
  }
  return cnt + 1;

}

// Complete the evenForest function below.
int evenForest(int n, int m, vector<int> a, vector<int> b) {
  for (int i = 0; i < m; i++) {
    addEdge(b[i], a[i]);
  }

  int cnt = dfs(0);
  if (cnt % 2 == 0) {
    ans--;
  }
  return ans;

}