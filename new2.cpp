#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

// int MOD=1000000000;

int i, j, k, n, m, ans = 0, cnt = 0, sum = 0,temp;
vector<int>c,b;

vector<vector<int>> multiply(vector<vector<int>> A,vector<vector<int>> B,int k){
	vector<vector<int>> C(k,vector<int>(k));
	for (int i = 0; i <= k; ++i)
	{
		for (int j = 1; j <=k; ++j)
		{
			for (int x = 1; x <=k; ++x)
			{
				C[i][j]=C[i][j]+(A[i][j]*B[i][j]);
			}
		}
	}
	return C;
}

vector<vector<int>> power(vector<vector<int>>A,int p,int k){
	if(n==1){
		return A;
	}
	else{
		if(p&1){
			return multiply(A,power(A,n-1,k),k);
		}
		else{
			vector<vector<int>> X=power(A,n/2,k);
			return multiply(X,X,k);
		}
	}
}

int compute(int n,int k){
	vector<vector<int>> T(k,vector<int>(k));
	if (n==0){
		return 0;
	}
	else if(n<=k){
		return b[n];		
	}
	else{
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 1; j <= k; ++j)
			{
				if(i<k){
					if(i==j+1){
						T[i][j]=1;
					}
					else{
						T[i][j]=0;
					}
				}
				else{
					T[i][j]=c[k-(j-1)];
				}
			}
		}
	}
	T=power(T,n-1,k);
	int res=0;
	for (int i = 1; i <=k; ++i)
	{
			res=(res+(T[1][i]*b[i]));
	}
	return res;
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
		cin>>k;
		for (int i = 1; i <= k; ++i)
		{
			cin>>temp;
			c.pb(temp);
		}
		for (int i = 1; i <= k; ++i)
		{
			cin>>temp;
			b.pb(temp);
		}
		cin>>n;
		compute(n,k);

	}
}