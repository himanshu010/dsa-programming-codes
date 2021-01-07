#define pb push_back
#define P pair<int, int>
#define F first
#define S second

vector<vector<int>> graph;
vector<bool>visited;

class Solution {
public:

    void addEdge(int l, int r) {
        graph[l].pb(r);
        graph[r].pb(l);
    }

    int bfs(int src, int dst) {

        queue<P> qu;
        qu.push({src, 1});

        while (!qu.empty()) {
            P cur = qu.front();
            qu.pop();
            visited[cur.F] = 1;
            for (auto x : graph[cur.F]) {
                if (!visited[x]) {
                    visited[x] = 1;
                    qu.push({x, cur.S + 1});
                    if (x == dst) {
                        return cur.S + 1;
                    }
                }
            }
        }
        return 0;
    }


    bool check(string a, string b) {
        int i = 0, j = 0;
        int cnt = 0;
        while (i < a.size() and j < b.size()) {
            if (cnt > 1) {
                break;
            }
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else {
                cnt++;
                j++;
                i++;
            }
        }
        if (cnt > 1) {
            return false;
        }
        return true;
    }

    int ladderLength(string a, string b, vector<string>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = v.size();

        graph.clear();
        graph.resize(n + 5);

        visited.clear();
        visited.resize(n + 5);
        fill(visited.begin(), visited.end(), 0);


        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(v[i], v[j])) {
                    addEdge(i + 1, j + 1);
                }
            }
        }

        bool exist = 0;
        int dst;

        for (int i = 0; i < n; i++) {
            if (check(a, v[i])) {
                addEdge(0, i + 1);
            }
            if (v[i].compare(b) == 0) {
                exist = 1;
                dst = i + 1;
            }
        }

        if (exist) {
            return bfs(0, dst);
        }
        return 0;
    }
};