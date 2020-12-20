#include <iostream>
#include <vector>
#define MOD 1000000000
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
#define endl '\n'

using namespace std;

vector<vector<int>> multiply(int k, vector<vector<int>> A,
                             vector<vector<int>> B) {

  vector<vector<int>> C(k, vector<int>(k));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      for (int g = 0; g < k; ++g) {
        C[i][j] = C[i][j] + (A[i][g] * B[g][j] % MOD) % MOD;
      }
    }
  }

  return C;
}

vector<vector<int>> power(int k, vector<vector<int>> t, int p) {
  if (p == 1) {
    return t;
  }

  if (p & 1) {
    return multiply(k, t, power(k, t, p - 1));
  }
  return multiply(k, power(k, t, p / 2), power(k, t, p / 2));
}

vector<vector<int>> transformation_matrix(int k, vector<int> b, vector<int> c) {
  vector<vector<int>> trans_M(k, vector<int>(k, 0));
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i != k - 1) {
        if (j == i + 1) {
          trans_M[i][j] = 1;
        }
      } else {
        trans_M[i][j] = c[k - j - 1];
      }
    }
  }

  return trans_M;
}

int compute(int n, int k, vector<int> b, vector<int> c) {
  if (n == 0) {
    return 0;
  }

  if (n <= k) {
    return b[n - 1];
  }

  vector<vector<int>> trans_M = transformation_matrix(k, b, c);
  trans_M = power(k, trans_M, n - 1);

  int res = 0;
  for (int i = 0; i < k; ++i) {
    res = (res + (trans_M[0][i] * b[i]) % MOD) % MOD;
  }

  return res;
}

void solve(int tc) {
  int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> k;
  vector<int> b, c;

  for (int i = 0; i < k; ++i) {
    int temp;
    cin >> temp;
    b.push_back(temp);
  }
  for (int i = 0; i < k; ++i) {
    int temp;
    cin >> temp;
    c.push_back(temp);
  }
  cin >> n;

  ans = compute(n, k, b, c);
  cout << ans << endl;
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
    int tc = 1;
    solve(tc);
    tc++;
  }
}