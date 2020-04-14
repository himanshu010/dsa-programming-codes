#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mkp make_pair
#define MAX INT_MAX

template<typename T>
class Graph {
    map<T, list<T> > adjList;

public:
    Graph() {

    }
    void addEdge(T u, T v, bool bidir = 1) {
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
    int bfs(T src, T dest) {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        int ans;

        for (auto i : adjList) {
            dist[i.F] = MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty()) {
            T node = q.front();
            q.pop();

            //for neighbour of current node
            for (auto neighbour : adjList[node]) {
                if (dist[neighbour] == INT_MAX) {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        // Print the distance to all node
        for (auto i : adjList) {
            T node = i.first;
            // cout << "Dist of " << node << " is " << dist[node] << endl;
        }

        // T temp = dest;
        // while (temp != src) {
        //     cout << temp << "<--";
        //     temp = parent[temp];
        // }
        return dist[dest];
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
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, ladder, snake, m, ans = 0, cnt = 0, sum = 0;
        Graph <int> g;
        int board[101] = {0};
        cin >> ladder;
        for (int i = 0; i < ladder; ++i)
        {
            int l, r;
            cin >> l >> r;
            int jump = r - l;
            board[l] = jump;
        }
        cin >> snake;
        for (int i = 0; i < snake; ++i)
        {
            int l, r;
            cin >> r >> l;
            int fall = l - r;
            board[r] = fall;
        }

        //construct the graph

        for (int i = 0; i <= 100; ++i)
        {
            //At every node you can throw a die
            for (int dice = 1; dice <= 6; ++dice)
            {
                int v = i + dice + board[i + dice];
                g.addEdge(i, v, 0);
            }
        }

        // cin >> n;
        // for (int i = 0; i < n; ++i)
        // {   int l, r;
        //     bool bidir;
        //     cin >> l >> r >> bidir;
        //     g.addEdge(l, r, bidir);
        // }
        // g.print();
        cout << g.bfs(0, 100) << endl;

    }
}