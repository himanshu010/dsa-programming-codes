#define P pair<int, int>
#define F first
#define S second
#define pb push_back

bool check(int grid[N][N], int r, int c, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[r][i] == n or grid[i][c] == n)
        {
            return false;
        }
    }
    int p_r, p_c;
    p_r = (r / 3) * 3;
    p_c = (c / 3) * 3;

    for (int i = p_r; i < p_r + 3; i++)
    {
        for (int j = p_c; j < p_c + 3; j++)
        {
            if (grid[i][j] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int grid[N][N], vector<P> toFill, int cur, int n)
{
    if (cur == n)
    {
        return true;
    }

    int r = toFill[cur].F;
    int c = toFill[cur].S;

    for (int i = 1; i <= 9; i++)
    {
        if (check(grid, r, c, i))
        {
            grid[r][c] = i;
            if (solve(grid, toFill, cur + 1, n))
            {
                return true;
            }
            else
            {
                grid[r][c] = 0;
            }
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N])
{
    vector<P> toFill;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                toFill.pb({i, j});
            }
        }
    }

    int n = toFill.size();

    return solve(grid, toFill, 0, n);
}

void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << ' ';
        }
    }
}