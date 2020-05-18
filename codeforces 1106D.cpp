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
vector<vector<int>> graph(N);
vi ans;

vector<bool> visited(N);

void addEgde(int x, int y) {
    graph[x].pb(y);
    graph[y].pb(x);
}

void sortVector() {
    for (int i = 0; i < N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // for (auto x : graph[4]) {
    //     cout << x << " ";
    // }
}



set<int> can;
void DFSfunction(int cur, int par, int n) {

}

void solve() {
    int i, j, k, n, m, cnt = 0, sum = 0;
    fill(visited.begin(), visited.end(), 0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        addEgde(x, y);
    }
    sortVector();
    // DFSfunction(1, 0, n);
    ans.pb(1);
    visited[1] = 1;
    while (ans.size() < n) {
        int i = ans.back();
        for (auto nbr : graph[i]) {
            if (visited[nbr] == 0) {
                can.insert(nbr);
            }
        }

        auto it = can.begin();
        ans.pb((*it));
        visited[(*it)] = 1;
        can.erase(it);
    }
    for (auto x : ans) {
        cout << x << " ";
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