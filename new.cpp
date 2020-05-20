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


bool checkIfSubarrayWithSumZero(int *a, int n) {
    int pre = 0;
    unordered_set<int> s;
    for (int i = 0;i < n; ++i)
    {
        pre +=a[i];
        if (pre == 0 or s.find(pre) != s.end()) {
            return true;
        }
        s.insert(pre);
    }

    return false;
}



void solve() {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    bool b = checkIfSubarrayWithSumZero(a, n);

    if (b == 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
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