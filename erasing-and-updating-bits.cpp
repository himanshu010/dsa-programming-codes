#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int clearLASTbits (int n, int i){
	int a=(~0ll)<<i+1;
	n=n&a;
	return n;
}

int clearItoJbits(int n, int i,int j){
	int a=(~0ll)<<j+1;
	int b=1<<i-1;
	int mask=a|b;
	n=n&mask;
	return n;
}
int BitUpdater(int n,int m, int i, int j){
	n=n|(m<<i);
	return n;
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
		cin>>n>>i;
		cin>>j>>m;
		ans=clearItoJbits(n,i,j);
		int upd_ans=BitUpdater(ans,m,i,j);
		cout<<ans<<endl<<upd_ans<<endl;
	}
}