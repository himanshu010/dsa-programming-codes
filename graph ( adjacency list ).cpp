#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define mkp make_pair

class Graph
{
    int v;
    list<int> *edges;

  public:
    Graph(int m)
    {
        v = m;
        edges = new list<int>[v];
    }

    void addEdge(int l, int r, bool birdir)
    {
        edges[l].push_back(r);
        if (birdir)
        {
            edges[r].push_back(l);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < v; ++i)
        {
            cout << i << " --> ";
            for (auto vertex : edges[i])
            {
                cout << vertex << ",";
            }
            cout << endl;
        }
    }
};

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        Graph g(n);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 4, 1);
        g.addEdge(4, 3, 1);
        g.addEdge(1, 4, 1);
        g.addEdge(1, 2, 1);
        g.addEdge(2, 3, 1);
        g.addEdge(1, 3, 1);
        g.printAdjList();
    }
}