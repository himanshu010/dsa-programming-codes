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

void NaiveSearch(string str, string pat) {
    for (int i = 0; i <= (str.size() - pat.size()); ++i)
    {
        int j;
        for (int j = 0; j < pat.size(); ++j)
        {
            if (str[i + j] != pat[j]) {
                break;
            }
            // cout << j << " " << pat.size() << endl;
            if (j == pat.size() - 1) {
                cout << "Pattern is found at " << i << endl;
            }
        }
    }
}

void solve() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

    string str, pat;
    cin >> str >> pat;
    NaiveSearch(str, pat);

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