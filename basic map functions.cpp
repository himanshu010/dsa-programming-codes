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

using namespace std;

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    multimap<char, string> mp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char ch;
        string s;
        cin >> ch >> s;

        mp.insert({ch, s});
    }

    auto it = mp.end();
    it = prev(it, 2);
    // mp.erase(it);

    auto low = mp.lower_bound('b');
    auto upper = mp.upper_bound('b');

    cout << (*low).S;


    for (auto p : mp) {
        cout << p.F << " ----> " << p.S << endl;
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
        int tc = 1;
        solve(tc);
        tc++;
    }
}