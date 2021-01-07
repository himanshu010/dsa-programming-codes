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
vector<int> dist(100005, INT_MAX);

class comparePQ
{
  public:
    bool operator()(P a, P b)
    {
        return a.S > b.S;
    }
};

void addEgde(int l, int r, int w)
{
    graph[l].pb({r, w});
    graph[r].pb({l, w});
}

int dijkstra(int src, int dest, int n)
{
    dist.clear();
    dist.resize(100005);
    fill(dist.begin(), dist.end(), INT_MAX);
    map<int, int> mp;
    priority_queue<P, vector<P>, comparePQ> pq;

    pq.push({src, 0});
    while (!pq.empty() and mp.size() < n)
    {
        P cur = pq.top();
        int node = cur.F;
        int d = cur.S;
        pq.pop();
        if (mp.find(node) == mp.end())
        {
            if (node == dest)
            {
                return d;
            }
            mp[node] = d;
            for (auto x : graph[node])
            {
                if (d + x.S < dist[x.F])
                {
                    dist[x.F] = d + x.S;
                    pq.push({x.F, dist[x.F]});
                }
            }
        }
    }
    return -1;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<string> city(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> city[i];
    }

    for (int i = 0; i < m; ++i)
    {
        string l, r;
        cin >> l >> r;
        auto it1 = find(city.begin(), city.end(), l);
        auto it2 = find(city.begin(), city.end(), r);
        int a = it1 - city.begin();
        int b = it2 - city.begin();
        int w;
        cin >> w;

        addEgde(a, b, w);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string l, r;
        cin >> l >> r;
        auto it1 = find(city.begin(), city.end(), l);
        auto it2 = find(city.begin(), city.end(), r);
        int a = it1 - city.begin();
        int b = it2 - city.begin();

        cout << dijkstra(a, b, n) << endl;
    }
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