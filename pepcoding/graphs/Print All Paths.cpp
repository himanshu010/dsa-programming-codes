/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
|                                                           |
|                                                           |
*-----------------------------------------------------------*
*/
#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define PQ priority_queue
using namespace std;
vector<string> ans;
void dfs(int cur, int dst, vvi &graph, vb &visited, string path) {
    visited[cur] = 1;
    if (cur == dst) {
        ans.pb(path);
        cout << path << endl;
    }
    for (auto x : graph[cur]) {
        if (!visited[x]) {
            dfs(x, dst, graph, visited, path + (char)(x + '0'));
        }
    }
    visited[cur] = 0;
}

void solve(int tc) {
    int i, j, k, n, m, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vector<int>>graph(n);
    vb visited(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;
        graph[l].pb(r);
        graph[r].pb(l);
    }

    cin >> k >> j;
    string path = "";
    path += (char)(k + '0');
    dfs(k, j, graph, visited, path);
    sort(ans.begin(), ans.end());
}


int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}