#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int gcd(int a, int b){
    int ans;
    if(b>a){
        int temp=a;
        a=b;
        b=temp;
    }
    if(b!=0){
        ans=gcd(b,a%b);
    }
    else{
        return a;
    }
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
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin>>j>>k;
        ans=gcd(j,k);
        cout<<ans;
    }
}