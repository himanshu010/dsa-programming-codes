#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class Graph {
    map<int, list<int>> mp;
public:
    void addEdge(int x, int y) {
        mp[x].push_back(y);
    }

    void bfs(int src, int destination) {
        map<int, int> dis;
        queue<int> q;

        for (auto x : mp) {
            dis[x.first] = INT_MAX;
        }
        dis[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nbr : mp[node]) {
                if (dis[nbr] == INT_MAX) {
                    q.push(nbr);
                    dis[nbr] = dis[node] + 1;
                }
            }
        }
        cout << dis[destination] << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int board[100] = {0};
        int ladders, snakes, s, e;
        cin >> ladders;
        while (ladders--) {
            cin >> s >> e;
            board[s] = (e - s);
        }
        cin >> snakes;
        while (snakes--) {
            cin >> e >> s;
            board[e] = (s - e);
        }

        Graph g;
        for (int i = 1; i <= 100; i++) {
            for (int dice = 1; dice <= 6; dice++) {
                int j = i + dice;
                j = j + board[j];
                if (j <= 100) {
                    g.addEdge(i, j);
                }
            }
        }
        g.addEdge(100, 100);
        g.bfs(1, 100);
    }
    return 0;
}