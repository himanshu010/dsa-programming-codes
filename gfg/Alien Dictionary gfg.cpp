class Solution {
public:

    string bfs(int src, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &required) {
        queue<int> qu;
        string ans;
        qu.push(src);
        visited[src] = 1;
        while (!qu.empty()) {
            int cur = qu.front();
            ans += (char)(cur + 97);
            qu.pop();
            visited[cur] = 1;
            for (auto nbr : graph[cur]) {
                if (required[nbr] > 0) {
                    required[nbr]--;
                }
                if (required[nbr] == 0 and !visited[nbr]) {
                    qu.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }

        return ans;
    }

    string findOrder(string dict[], int n, int k) {
        vector<int> required(26, -1);
        vector<bool> visited(26, 0);

        vector<vector<int>>graph(26);
        string a, b;
        int temp = 0;
        for (int i = 0; i < n - 1; i++) {
            a = dict[i];
            b = dict[i + 1];
            int l = 0, k = 0;
            while (l < a.size() and k < b.size()) {
                if (a[l] == b[k]) {
                    l++;
                    k++;
                }
                else {
                    if (required[(int)a[l] - (int)'a'] == -1) {
                        required[(int)a[l] - (int)'a'] = 0;
                    }
                    if (required[(int)b[k] - (int)'a'] == -1) {
                        required[(int)b[k] - (int)'a'] = 0;
                    }
                    required[(int)b[k] - (int)'a'] += 1;
                    graph[(int)a[l] - (int)'a'].push_back((int)b[k] - (int)'a');
                    break;
                }
            }

        }
        string ans;

        for (int i = 0; i < 26; i++) {
            if (required[i] == 0 and visited[i] == 0) {
                ans += bfs(i, graph, visited, required);
            }
        }
        return ans;
    }
};