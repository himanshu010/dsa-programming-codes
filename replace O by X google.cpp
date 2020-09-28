/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|               ( himanshuaswal.codes )                     |
|                                                           |
|                                                           |
*-----------------------------------------------------------*

*/

#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map

using namespace std;

vector<vector<char>>mat;
void floodFill(vector<vector<char>> &a, int i, int j, int n, int m) {
  // cout << i << " " << j << endl;
  if (a[i][j] == '-') {
    a[i][j] = 'O';


    bool left = 1;
    bool right = 1;
    bool up = 1;
    bool down = 1;

    if (i == 0) {
      up = 0;
    }
    if (i == n - 1) {
      down = 0;
    }
    if (j == 0) {
      left = 0;
    }
    if (j == m - 1) {
      right = 0;
    }

    if (left) {
      floodFill(a, i, j - 1, n, m);
    }
    if (right) {
      floodFill(a, i, j + 1, n, m);
    }
    if (up) {
      floodFill(a, i - 1, j, n, m);
    }
    if (down) {
      floodFill(a, i + 1, j, n, m);
    }
  }


}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> a[i][j];
      if (a[i][j] == 'O') {
        a[i][j] = '-';
      }

    }
  }

  mat = a;
  for (int i = 0; i < m; ++i)
  {
    if (a[0][i] == '-') {
      floodFill(mat, 0, i, n, m);
    }
    if (a[n - 1][i] == '-') {
      floodFill(mat, n - 1, i, n, m);
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (a[i][0] == '-') {
      floodFill(mat, i, 0, n, m);
    }
    if (a[i][m - 1] == '-') {
      floodFill(mat, i, m - 1, n, m);
    }
  }



  for (auto x : mat) {
    for (auto y : x) {
      if (y == '-') {
        y = 'X';
      }
      cout << y << " ";
    }
    // cout << endl;
  }
  cout << endl;




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
  int tc = 1;
  int t; cin >> t; while (t--)
  {
    solve(tc);
    tc++;
  }
}