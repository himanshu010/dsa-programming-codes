/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
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

<<<<<<< HEAD
int quickSortHelper(vi &a, int s, int e) {
    int p = e;
    int n = a.size();
    int j = s;
    for (int  i = s; i < e; ++i)
    {
        if (a[i] < a[p]) {
            swap(a[i], a[j]);
            j++;
        }
    }

    swap(a[e], a[j]);
    return j;
}

void quickSort(vi &a, int s, int e) {
    if (s >= e) {
        return;
    }
    int p = quickSortHelper(a, s, e);
    // int p = s + 1;

    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}


void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
=======
int friendsPairing(int n) {
    if (n <= 2) {
        return n;
    }
    return friendsPairing(n - 1) + ((n - 1) * friendsPairing(n - 2));
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vi dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + ((i - 1) * dp[i - 2]);
    }
    for (auto x : dp) {
        cout << x << ' ';
>>>>>>> fa9d751716ce42258b0a6bc2e5444b95ea96b5e7
    }
    cout << endl;
    cout << dp[n] << endl;
    cout << friendsPairing(n);

<<<<<<< HEAD
    quickSort(a, 0, n - 1);
    for (auto x : a) {
        cout << x << ' ';
    }

=======
>>>>>>> fa9d751716ce42258b0a6bc2e5444b95ea96b5e7
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