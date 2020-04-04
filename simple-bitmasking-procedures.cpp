#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

bool ODD(int n){
	if (n&1ll)return 1;
	else return 0;
}

int IthBit(int n,int i){
	int mask=(1ll<<i);
	int bit = n&mask;
	if(bit>0) return 1;
	else return 0;
}
int setIthBit(int n, int i){
	int mask=(1ll<<i);
	n=n|mask;
	return n;
}
int clearBit(int n,int i){
	int mask=~(1<<i);
	n=n&mask;
	return n;
}
int setBitToV(int n,int i,int v){
	n=clearBit(n,i);
	int mask=v<<i;
	n=n|mask;
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
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0,v;
		cin>>n;
		cin>>i;
		cin>>v;
		string a;
		// cin>>i;
		ans=ODD(n);
		if (ans==1) a="true";
		else a="false";
		cout<<"Is "<<n<<" Odd : "<<a<<endl;

		int bit = IthBit(n,i);
		cout<<i <<"th bit of "<<n<<" is : "<< bit<<endl;

		cnt= setIthBit(n,i);
		cout<<"After setting "<<i<<"th bit to 1, result is : "<<cnt<<endl;

		int clr=clearBit(n,i);
		cout<<"After clearing "<<i<<"th Bit , result is : "<<clr<<endl;

		int sb=setBitToV(n,i,v);
		cout<<"After setting "<<i<<"th Bit to "<<v<<", result is : "<<sb<<endl;
	}
}