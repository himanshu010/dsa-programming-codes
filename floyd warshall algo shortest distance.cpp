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
#define R return

using namespace std;

const int N = 100005, M = 22;
vector <vector<P>> adj(N);
void addedge(int x, int y, int w) {
    adj[x].pb({y, w});
    adj[y].pb({x, w});
}


vvi all_pair_shortest_path(int n, vector<vector<P>> &adj) {
    vvi dist(n + 1, vi (n + 1, INT_MAX));

    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
        for (P ed : adj[i]) {
            int nbr = ed.F;
            int w = ed.S;
            dist[i][nbr] = w;

        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}



void solve() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // x--;
        // y--;
        addedge(x, y, w);
        // cout << x << y << w << endl;

    }
    vector<vector<int>> sol = all_pair_shortest_path(n, adj);
    for (auto x : sol) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    // cin >> i >> j;
    // cout << sol[i][j] << endl;


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
    // int t;cin>>t;while(t--)
    {
        solve();
    }
}