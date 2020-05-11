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
vector<int> gr[N];
int visited[N];
bool odd_cycle = 0;

void dfs(int cur, int par, int col) {
    for (auto child : gr[cur]) {
        visited[cur] = col;
        if (visited[child] == 0) {
            dfs(child, cur, 3 - col);
        }
        else if (child != par && col == visited[child]) {
            odd_cycle = 1;
        }
    }
    return;
}

void solve() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1, 0, 1);
    // cout << odd_cycle << endl;
    if (odd_cycle) {
        cout <<  "Not Bipartite" << endl;
    }
    else {
        cout << "Bipartite" << endl;
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