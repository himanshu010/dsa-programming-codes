#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

void permute(char *in, int i)
{
    if (in[i] == '\0')
    {
        cout << in << endl;
        return;
    }
    for (int j = i; in[j] != '\0'; ++j)
    {
        swap(in[i], in[j]);
        permute(in, i + 1);
        swap(in[i], in[j]);
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;

    // int t;cin>>t;while(t--)
    {
        char in[100];
        cin >> in;
        permute(in, 0);
    }
}