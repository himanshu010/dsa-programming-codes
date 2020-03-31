#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mod 1000000007

int ConvertStringToInt(string a,int m){

    int ans=0; 
    for (int i = 0; i < a.size(); ++i)
    {
        ans=((ans*10)%m+(a[i]-'0'))%m;
    }
    return ans;
}

int power(int a, int b){
    int ans;

    if(b==0){
        return 1;
    }
    else{
        ans=(power(a,b/2))%mod;
        ans=(ans*ans)%mod;
        // cout<<ans<<"ananananan"<<endl;
        if(b&1){
            return ((ans*a)%mod);
        }
        else{
            return (ans%mod);
        }
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        string a, b;
        cin>>a>>b;

        int num=ConvertStringToInt(a,mod);
        int pow=ConvertStringToInt(b,mod-1);
        ans=power(num,pow);
        cout<<ans<<endl;
    }
}