/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|                       (himanshu010)                       |
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


int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t; while (t--)
    {
        int i, j, k, n, r, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> r;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        bool isvisit[n];
        for (int i = 0; i < n; ++i)
        {
            isvisit[i] = false;
        }

        for (int i = 0; i < n - r; ++i)
        {
            if (isvisit[i] == true) {
                continue;
            }
            vector<int> sorted;
            for (int j = i; j < n; j = j + r)
            {
                sorted.pb(a[j]);
                isvisit[j] = true;
            }
            int g = 0;
            sort(sorted.begin(), sorted.end());
            for (int j = i; j < n; j = j + r)
            {
                a[j] = sorted[g];
                g++;
            }

        }

        for (int i = 1; i < n; i++)
        {

            if (a[i] < a[i - 1])
            {
                cnt++;;
            }
        }

        if (cnt == 0) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }




    }
}