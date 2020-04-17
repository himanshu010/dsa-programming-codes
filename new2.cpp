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
        int x, y;
        int R = 1;
        int B = 1;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;
        while (R <= x && B <= y) {
            if (x < y) {
                cout << "----" << endl;
                R = R + B;
            }
            else {
                cout << "=====" << endl;
                B = B + R;
            }
        }
        cout << R << " " << B << endl;
        cout << B << R <<



    }
}