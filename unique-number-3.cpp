#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back


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
        int i, j, b, bit, k, n, m, ans = 0, cnt = 0, sum = 0, temp;
        cin >> n;
        int a[64] = {0};
        for (int i = 0; i < n; ++i)
        {
            // cout<<(1&4)<<"--"<<endl;
            cin >> temp;
            j = 0;
            // a = convertToBinary(temp);
            while(temp > 0)
            {
                int mask = 1 << i;
                // cout<<mask<<endl;
                bit = (temp & 1);
                if (bit > 0)b = 1;
                else b = 0;
                temp = temp >> 1;
                // cout<<b<<endl;
                a[j] = a[j] + b;
                // cout<<b;

                // cout<<j;
                // cout<<a[j];
                j++;
            }
        }
        for (int i = 0; i < 64; ++i)
        {
            a[i]=a[i]%3;
            ans+=a[i]<<i;
        }
        cout<<ans;
    }
}