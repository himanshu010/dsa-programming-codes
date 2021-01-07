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
using namespace std;

vector<vector<P>>graph(100005);
vector<int>dist(100005, INT_MAX);

class ComparePQ
{
public:
    bool operator()(P a, P b) {
        return a.S > b.S;
    }

};

void dijkstra(int src, int n) {
    map<int, int>mp;
    priority_queue<P, vector<P>, ComparePQ> pq;
    dist[src] = 0;

    pq.push({src, 0});
    while (!pq.empty() and mp.size() < n) {

        P cur = pq.top();
        int node = cur.F;
        int d = cur.S;
        // cout << node << ' ' << d << endl;
        if (mp.find(node) == mp.end()) {
            mp[node] = d;
            for (auto x : graph[node]) {
                if (dist[x.F] > d + x.S) {
                    dist[x.F] = d + x.S;
                    pq.push({x.F, dist[x.F]});
                }
            }
        }
        pq.pop();

    }

    for (auto x : mp) {
        cout << x.F << ' ' << x.S << endl;
    }
}

void addEgde(int l, int r, int w) {
    graph[l].pb({r, w});
    graph[r].pb({l, w});
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;

        addEgde(l, r, w);
    }


    dijkstra(0, n);
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
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}