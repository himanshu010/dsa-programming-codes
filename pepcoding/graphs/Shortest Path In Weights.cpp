/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
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
#define PQ priority_queue
using namespace std;

class compare
{
  public:
    bool operator()(pair<string, P> a, pair<string, P> b)
    {
        return a.S.S > b.S.S;
    }
};

void dijkstra(int src, vector<vector<P>> &graph, string path, int n)
{

    vi dist(n, INT_MAX);
    vb visited(n, 0);
    // visited[src]=1;
    dist[src] = 0;

    priority_queue<pair<string, P>, vector<pair<string, P>>, compare> pq;
    pq.push({path + (char)(src + '0'), {src, 0}});

    while (!pq.empty())
    {
        int cur = pq.top().S.F;
        int d = pq.top().S.S;
        string p = pq.top().F;
        pq.pop();
        if (!visited[cur])
        {
            visited[cur] = 1;
            cout << cur << " via " << p << " @ " << d << endl;
            for (auto x : graph[cur])
            {
                if (dist[x.F] > dist[cur] + x.S)
                {
                    dist[x.F] = dist[cur] + x.S;
                    pq.push({p + (char)(x.F + '0'), {x.F, dist[x.F]}});
                }
            }
        }
    }
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;

    vector<vector<P>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int l, r, w;
        cin >> l >> r >> w;

        graph[l].push_back({r, w});
        graph[r].push_back({l, w});
    }

    cin >> k;
    dijkstra(k, graph, "", n);
}

int32_t main()
{
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