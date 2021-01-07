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
using namespace std;

vector<vector<P>> graph(100005);
vector<bool> visited(100005, 0);
vector<int> dist(100005, INT_MAX);

void addEdge(int l, int r, int w)
{
    graph[l].pb({r, w});
    graph[r].pb({l, w});
}

class ComparePQ
{
  public:
    bool operator()(P a, P b)
    {
        return a.S > b.S;
    }
};

map<int, int> mp1, mp2;
void dijkstra(int src, int n)
{
    priority_queue<P, vector<P>, ComparePQ> pq;
    dist[src] = 0;

    pq.push({src, 0});
    while (!pq.empty() and mp1.size() < n)
    {

        P cur = pq.top();
        int node = cur.F;
        int d = cur.S;
        // cout << node << ' ' << d << endl;
        if (mp1.find(node) == mp1.end())
        {

            mp1[node] = d;
            for (auto x : graph[node])
            {
                if (dist[x.F] > d + x.S)
                {
                    dist[x.F] = d + x.S;
                    pq.push({x.F, dist[x.F]});
                }
            }
        }
        pq.pop();
    }
}

void dijkstra2(int src, int n)
{
    priority_queue<P, vector<P>, ComparePQ> pq;
    dist[src] = 0;

    pq.push({src, 0});
    while (!pq.empty() and mp2.size() < n)
    {

        P cur = pq.top();
        int node = cur.F;
        int d = cur.S;
        // cout << node << ' ' << d << endl;
        if (mp2.find(node) == mp2.end())
        {

            mp2[node] = d;
            for (auto x : graph[node])
            {
                if (dist[x.F] > d + x.S)
                {
                    dist[x.F] = d + x.S;
                    pq.push({x.F, dist[x.F]});
                }
            }
        }
        pq.pop();
    }
}

// void dijkstra(int src, int dst) {
//   visited.clear(); visited.resize(100005);
//   fill(visited.begin(), visited.end(), 0);
//   [src] = 0;

//   priority_queue<P> qu;
//   qu.push({src, 0});
//   while (!qu.empty()) {
//     P cur = qu.top();
//     if (visited[cur.F]) {
//       continue;
//     }
//     visited[cur.F] = 1;
//     for (auto nbr : graph[cur.F]) {
//       if ([nbr.F] > cur.S + nbr.S and !visited[nbr.F]) {
//         [nbr.F] = cur.S + nbr.S;
//         qu.push({nbr.F, [nbr.F]});
//       }
//     }
//     // visited[cur.F] = 0;
//   }

//   if ([dst] == INT_MAX) {
//     cout << -1 << endl;
//     return;
//   }
//   cout << [dst] << endl;
// }

// void bfs(int src, int dst, vi cake, int n, int mx) {
//   queue<int> qu;
//   qu.push(src);
//   while (!qu.empty()) {
//     int cur = qu.front();
//     if (visited[cur]) {
//       continue;
//     }

//     for (auto x : cake) {
//       if (x == cur) {
//         dijkstra(x, n, dst, mx);
//         return;
//       }
//     }
//     visited[cur] = 1;
//     qu.pop();
//     for (auto nbr : graph[cur]) {
//       if (!visited[nbr.F]) {
//         qu.push(nbr.F);
//       }
//     }
//   }

//   cout << -1 << endl;
// }

void solve(int tc)
{
    int i, j, k, n, x, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m >> k >> x;
    vector<int> cake(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> cake[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;
        addEdge(l, r, w);
    }

    int dst, src;
    cin >> dst >> src;

    dijkstra(src, n);
    dijkstra2(dst, n);
    bool flag = 0;
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (mp1.find(i) != mp1.end() and mp2.find(i) != mp2.end())
        {
            flag = 1;
            // cout << i << ' ' << mp1[i] << ' ' << mp2[i] << endl;
            mn = min(mn, mp1[i] + mp2[i]);
        }
    }

    if (flag)
    {
        if (mn <= x)
        {
            cout << mn << endl;
            return;
        }
    }

    cout << -1 << endl;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}