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

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }


    vector<bool> b(n, 0);
    if (a[0] & 1) {
        b[0] = 1;
    }


    for (int i = 1; i < n; ++i)
    {
        if (b[i - 1]) {
            if (a[i] % 2 == 0) {
                b[i] = 1;
            }
        }
        else {
            if (a[i] & 1) {
                b[i] = 1;
            }
        }
    }

    if (b[n - 1]) {
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
    return;


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