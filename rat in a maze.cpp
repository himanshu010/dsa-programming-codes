#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int one = 1;
bool ratInMaze(char maze[][1000], int soln[][1000], int i, int j, int m, int n)
{

    if (i == m && j == n && one == 1)
    {
        soln[m][n] = 1;
        //print the pathr̥
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        one++;
        return true;
    }

    //Rat should be inside grid
    if (i > m || j > n)
    {
        return false;
    }

    if (maze[i][j] == 'X')
    {
        return false;
    }
    std::vector<char> v;

    //Assume solution Exists through current cell

    soln[i][j] = 1;

    bool right = ratInMaze(maze, soln, i, j + 1, m, n);
    bool down = ratInMaze(maze, soln, i + 1, j, m, n);

    //Backtracking
    soln[i][j] = 0;


    if (right || down)
    {
        return true;
    }
    return true;


}
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
        int i, j, k, cnt = 0, sum = 0;
        int n, m;
        cin >> n >> m;
        char maze[n][1000];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> maze[i][j];
            }
        }

        int soln[n][1000] = {0};
        bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
        if (ans = false)
        {
            cout << "-1";
        }


    }
}