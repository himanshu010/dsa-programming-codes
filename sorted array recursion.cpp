#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

bool isSorted(queue<int> qu, int n) {
    if (qu.size() - 1 == 0) {
        return true;
    }
    int num1 = qu.front();
    qu.pop();
    int num2 = qu.front();
    cout << num1 << "  __compared to__   " << num2 << endl;

    if (num1 < num2 && isSorted(qu, n)) {
        return true;
    }
    return false;

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
        queue<int> qu;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            qu.push(temp);

        }
        if (isSorted(qu, n)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

    }
}