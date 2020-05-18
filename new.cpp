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

vvi graph(N);

vi parent(N);

vb visited(N, 0);

void addEdge(int x, int y) {
    graph[x].pb(y);
}


void DFS(int cur, int par) {
    visited[cur] = 1;
    if (cur != 1) {
        parent[cur] = par;
    }
    else {
        parent[1] = -1;
    }

    for (auto child : graph[cur]) {
        DFS(child, cur);
    }

}





void solve() {
    int i, j, k, q, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;

        addEdge(x, y);
    }
    DFS(1, 0);

    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << parent[i] << endl;
    // }

    while (q--) {
        int node, d;
        cin >> node >> d;
        int curParent = 0;
        while (d--) {

            // cout << curParent << " " << node << endl;
            if (node == -1 or curParent == -1) {
                break;
            }
            curParent = parent[node];
            node = curParent;
        }
        if (curParent == 0) {
            cout << -1 << endl;
        }
        else {
            cout << curParent << endl;
        }

    }


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