/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
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
#define PQ priority_queue
using namespace std;


void changeMatrix(vvi &a, int n, int m, int i, int j) {
    int rightValue = j + 1 < m ? a[i][j + 1] : INT_MAX;
    int downValue = i + 1 < n ? a[i + 1][j] : INT_MAX;

    if (rightValue == INT_MAX and downValue == INT_MAX) {
        return;
    }


    if (downValue < rightValue) {
        a[i][j] = downValue;
        a[i + 1][j] = INT_MAX;
        changeMatrix(a, n, m, i + 1, j);
    }
    else {
        a[i][j] = rightValue;
        a[i][j + 1] = INT_MAX;
        changeMatrix(a, n, m, i, j + 1);
    }
}

int calculateSmallest(vvi &a, int n, int m) {

    changeMatrix(a, n, m, 0, 0);

    return a[0][0];
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n * n; ++i)
    {
        cout << calculateSmallest(a, n, m) << ' ';
    }

}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}