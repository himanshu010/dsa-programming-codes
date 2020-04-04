#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

vector<int> primes (int n) {
    vector<int> prime;
    if (n % 2 == 0) {
        prime.pb(2);
        while (n % 2 == 0) {
            n = n / 2;
        }
    }
    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0) {
            prime.pb(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) {
        prime.pb(n);
    }
    return prime;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, cnt = 0, sum = 0;
        cin >> n;
        int ans = n;
        vector<int> prime = primes(n);
        for (auto x : prime) {
            ans = ans - (ans / x);
        }
        cout << ans << endl;
    }
}