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

vector<int> dif(3, 0);
vector<int> multi_factor(3, 0);


void Check(int *a, int *b) {

    set<int> sd, sf;

    int diff_same = 0;
    int factor_same = 0;

    int d1;
    int d2;

    for (int i = 0; i < 3; ++i)
    {
        diff[i] = b[i] - a[i];
        if (b[i] % a[i] == 0) {
            multi_factor[i] = b[i] / a[i];
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i != j and multi_factor[i] == multi_factor[j] and multi_factor[i] == 0) {
                factor_same++;
                d1 = multi_factor[i];
                sf.insert(i);
                sf.insert(j);
            }

            if (i != j and dif[i] == dif[j] and dif[i] == 0) {
                d2 = dif[i];
                sd.insert(i);
                sd.insert(j);
            }
        }

        if (diff_same > factor_same) {
            for (auto x : sd) {
                a[x] = a[x] + d2;
            }
        }
        else if (diff_same < factor_same) {
            for (auto x : sf) {
                a[x] = a[x] * d2;
            }
        }
        else {

        }
    }
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    int a[3];
    int b[3];

    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        cin >> b[i];
    }


    Check(a, b);

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