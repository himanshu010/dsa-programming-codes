#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mkp make_pair


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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int B[n], W[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> B[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> W[i];
        }
        sort(B, B + n);
        sort(W, W + n);
        for (int i = 0; i < n; ++i)
        {
            sum += abs(B[i] - W[i]);
        }
        cout << sum << endl;
    }
}