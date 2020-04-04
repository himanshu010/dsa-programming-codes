#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int steps = 0;

void TowerOfHanoi(int n, char source, char helper, char destination) {
    //Base Case
    if (n == 0) {
        return;
    }
    TowerOfHanoi(n - 1, source, destination, helper);
    cout << "Shifting " << n << " from " << source << " to " << destination << endl;
    TowerOfHanoi(n - 1, helper, source, destination);
    steps++;
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        TowerOfHanoi(n, 'A', 'B', 'C');
        cout << endl << "Total Steps taken : " << steps << endl;

    }
}