/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|                       (himanshu010)                       |
|                                                           |
|                                                           |
*-----------------------------------------------------------*


*/

#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
// #define R return

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int R, C;

void printMatrix(char matrix[][50]) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

void floodFill(char mat[][50], int i, int j, char ch, char color) {
  // base case
  if (i < 0 || j < 0 || i >= R || j >= C) {
    return;
  }

  // Figure boundary condition
  if (mat[i][j] != ch) {
    return;
  }

  // recursive call
  mat[i][j] = color;
  printMatrix(mat);
  for (int k = 0; k < 4; k++) {
    floodFill(mat, i + dx[k], j + dy[k], ch, color);
  }
}

int32_t main() {
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

    char input[15][50];
    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        cin >> input[i][j];
      }
    }
    printMatrix(input);
    floodFill(input, 8, 13, '.', 'r');
    printMatrix(input);
  }
}