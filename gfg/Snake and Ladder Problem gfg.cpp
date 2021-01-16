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

vvi graph;
vb visited;

class comparePQ {
public:
    bool operator()(P a, P b) {
        return  a.S > b.S;
    }
};

void addEdge(int l, int r) {
    graph[l].pb(r);
}

void bfs(int src, int dst) {
    PQ<P, vector<P>, comparePQ> qu;
    qu.push({src, 0});

    while (!qu.empty()) {
        P cur = qu.top();
        if (cur.F == dst) {
            cout << cur.S << endl;
            return;
        }
        visited[cur.F] = 1;
        qu.pop();

        for (auto nbr : graph[cur.F]) {
            if (!visited[nbr]) {
                qu.push({nbr, cur.S});
                visited[nbr] = 1;
            }
        }

        for (int i = cur.F + 1; i <= cur.F + 6 ; ++i)
        {
            if (i >= 1 and i <= 30 and !visited[i]) {
                qu.push({i, cur.S + 1});
                visited[i] = 1;
            }
        }
    }

}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    n = 31;
    cin >> m;
    graph.clear();
    graph.resize(n + 1);

    visited.clear();
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        addEdge(l, r);
    }

    bfs(1, 30);
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    int t; cin >> t; while (t--)
    {
        solve(tc);
        tc++;
    }
}