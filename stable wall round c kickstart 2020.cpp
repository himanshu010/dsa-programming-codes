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

char charlist[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                     'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                     'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const int N = 100005, M = 22;
vector<char> ansVector;
vector<vector<int>> graph(N);

void addEdge(int x, int y) { graph[x].pb(y); }

void TopologicalBFS(int v, int *required, vector<int> vertices) {
  int sum = 0;
  for (auto x : graph) {
    for (auto y : x) {
      required[y]++;
    }
  }

  // for (int i = 0; i < v; ++i)
  // {
  //     cout << required[i] << " ";
  // }
  queue<int> q;

  for (int i = 0; i < v; ++i) {
    // Jiske liye kisi bhi chij ki jarurat nhi he ussey nikal lenge
    if (required[vertices[i]] == 0) {
      q.push(vertices[i]);
    }
  }

  while (!q.empty()) {
    int top = q.front();
    // cout << charlist[top];
    ansVector.pb(charlist[top]);
    q.pop();

    for (auto x : graph[top]) {
      required[x]--;
      if (required[x] == 0) {
        q.push(x);
      }
    }
  }
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

  int r, c;
  cin >> r >> c;
  char a[r][c];

  set<pair<char, char>> v;
  vector<pair<int, int>> st;
  set<int> vert;
  vector<int> vertices;
  set<char> set2;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> a[i][j];
      set2.insert(a[i][j]);
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i != r - 1) {

        if (a[i + 1][j] != a[i][j]) {
          v.insert({a[i + 1][j], a[i][j]});
        }
      }
    }
  }
  vector<char> set3, set4;
  for (auto x : set2) {
    set3.pb(x);
  }
  if (v.size() != 0) {
    for (auto y : v) {
      set4.pb(y.F);
      set4.pb(y.S);
    }

    for (int i = 0; i < set3.size(); ++i) {
      int cnt = 0;
      for (int j = 0; j < set4.size(); ++j) {
        if (set3[i] == set4[j]) {
          // cout << "----";
          cnt++;
        }
      }
      if (cnt == 0) {
        ansVector.pb(set3[i]);
      }
      // cout << endl;
    }
  } else {
    for (auto x : set3) {
      ansVector.pb(x);
    }
  }

  int numff, numss;
  for (auto x : v) {
    // cout << x.F << " " << x.S << endl;
    for (int i = 0; i < 26; ++i) {
      if (x.F == charlist[i]) {
        numff = i;
        // cout << "---";
      }
      if (x.S == charlist[i]) {
        numss = i;
      }
    }

    st.pb(make_pair(numff, numss));
    vert.insert(numff);

    vert.insert(numss);
  }

  for (auto x : vert) {
    vertices.pb(x);
    // cout << x << "--" << endl;
  }

  // cin >> v >> m;
  int verticesNum = vertices.size();
  int edges = st.size();
  for (auto x : st) {
    addEdge(x.F, x.S);
  }
  int required[26] = {0};
  TopologicalBFS(verticesNum, required, vertices);
  // cout << sum << endl;
  if (ansVector.size() != set3.size()) {
    cout << "Case #" << tc << ": -1" << endl;
  } else {
    cout << "Case #" << tc << ": ";
    for (auto x : ansVector) {
      cout << x;
    }
    cout << endl;
  }
  graph.clear();
  ansVector.clear();
  graph.resize(N + 1);
}

int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  int t;
  cin >> t;
  while (t--) {
    solve(tc);
    tc++;
  }
}
