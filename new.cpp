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
    }

    quickSort(a, 0, n - 1);
    for (auto x : a) {
        cout << x << ' ';
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