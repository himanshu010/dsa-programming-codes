#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

bool compare(string a, string b){
    auto f= a.find(b);
    auto g= b.find(a);
    if (f!=string::npos)
    {
        return a.length()>b.length();
    }
    else
    if(g!=string::npos){
        return a.length()>b.length();
    }
    else{
        return a<b;
    }
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{	
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin>>n;
		string s[n+1];
		for (int i = 0; i < n+1; i++)
		{
			getline(cin,s[i]); 
		}
		sort(s,s+n+1,compare);
		for (int i = 0; i < n; i++){
			cout<<s[i]<<endl;
		}

	}
}