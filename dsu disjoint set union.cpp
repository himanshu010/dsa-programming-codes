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
#define R return

using namespace std;


struct dsu {
    vector<int> par;
    int total_comp;

    //initialise
    void init(int n) {
        par.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
        int total_comp = n;
    }

    int get_superparent(int x) {
        if (x == par[x]) {
            return x;
        }
        else {
            //path compression is used
            par[x] = get_superparent(par[x]);
        }
    }

    void unite(int x, int y) {
        int superparent_x = get_superparent(x);
        int superparent_y = get_superparent(y);
        if (superparent_x != superparent_y) {
            par[superparent_x] = superparent_y;
            total_comp--;
        }
    }
} G;

void solve() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

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
        solve();
    }
}