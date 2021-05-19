class Solution
{
  public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));
        vector<pair<int, int>> gr;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (box[i][j] == '*' or j == m - 1)
                {
                    ans[i][j] = cnt - '0';
                    cnt = 0;
                    gr.push_back({i, j});
                }
                if (box[i][j] == '#')
                {
                    cnt += 1;
                }
            }
        }

        for (auto x : gr)
        {
            int i = x.first;
            int j = x.second;
            int t = ans[i][j] + '0';
            if (t > 0 and box[i][j] == '.')
            {
                box[i][j] = '#';
                t--;
            }
            while (t-- and j > 0)
            {
                ans[i][--j] = '#';
            }
            ans[x.first][x.second] = box[x.first][x.second];
        }

        vector<vector<char>> a(m, vector<char>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = ans[n - 1 - j][i];
            }
        }

        return a;
    }
};