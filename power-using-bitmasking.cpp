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
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 1, cnt = 0, sum = 0,bit,mut=1;
        // float res=1;

        cin>>n>>m;
        // k=m;
        while(m>0){
            bit = m&1;
            // cout<<bit<<endl;
            m=m>>1;
            if (bit==1){
                ans=ans*n;
            }
            n=n*n;
        }
        cout<<ans;

    }
}