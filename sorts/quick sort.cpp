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

int quickSort_Helper(int* a, int n, int s, int e) {
    int pivot = e;
    int j = s;
    for (int i = s; i < e; ++i)
    {
        if (a[i] < a[pivot]) {
            swap(a[i], a[j++]);
        }
    }

    swap(a[j], a[pivot]);
    return j;
}

void quickSort(int *a, int n, int s, int e) {
    if (s >= e) {
        return;
    }

    int pivot = quickSort_Helper(a, n, s, e);
    quickSort(a, n, s, pivot - 1);
    quickSort(a, n, pivot + 1, e);
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    quickSort(a, n, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
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