#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mkp make_pair

template<typename T>
class Graph {
    map<T, list<T> > adjList;

public:
    Graph() {

    }
    void addEdge(T u, T v, bool bidir) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }
    void print() {
        for (auto i : adjList) {
            cout << i.F << " ---> ";
            for (auto entry : i.S) {
                cout << entry << ",";
            }
            cout << endl;
        }
    }
    void bfs(T src) {
        queue<T> q;
        map<T, bool> visited;

        q.push(src);
        visited[src] = 1;

        while (!q.empty()) {
            T node = q.front();
            cout << node << " ";
            q.pop();

            //for neighbour of current node
            for (auto neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }
};



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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        Graph <int> g;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {   int l, r;
            bool bidir;
            cin >> l >> r >> bidir;
            g.addEdge(l, r, bidir);
        }
        g.print();
        g.bfs(0);

    }
}