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


int reset[100005];


void KMPpreprocess(string pattern) {
    int i = 0, j = -1;
    reset[0] = -1;
    while (i < pattern.size()) {

        while (j >= 0 && pattern[i] != pattern[j]) {
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}

void KMPsearch(string str, string pattern) {
    KMPpreprocess(pattern);
    for (int i = 0; i < 50; ++i)
    {
        cout << reset[i] << " ";
    }
    cout << endl;
    int i = 0; int j = 0;
    while (i < str.size()) {
        while (j >= 0 and str[i] != pattern[j]) {
            j = reset[j];
        }
        i++;
        j++;
        if (j == pattern.size()) {
            cout << "Pattern is found at " << i - j << endl;
            j = reset[j];
        }
    }
}

void solve() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    for (int i = 0; i < 100005; ++i)
    {
        reset[i] = -1;
    }
    string str, pat;
    cin >> str >> pat;
    KMPsearch(str, pat);


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