#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int ans = fibonacci(n - 1) + fibonacci(n - 2);
    return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    {
        int i, j, k, n, m, cnt = 0, sum = 0;
        cin >> n;
        cout << fibonacci(n);
    }
}