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
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		string a("atm");
		string b("batman");
		{
			cout<<"Substring using Apaar\n";

			if (b.substr(0,a.size())==a){
				cout<<"a is a substring of b"<<endl;
			}
			else
			if(a.substr(0,b.size())==b){
				cout<<"b is a substring of a"<<endl;
			}
			else{
				cout<<"none of them is the substring of another"<<endl;
			}
		}
		{
			cout<<"\n\nsubstring using my code\n";
			auto f= a.find(b);
			auto g= b.find(a);
			if (f!=string::npos){
				cout<<"b is a substring of a"<<endl;
			} 
			else
			if (g!=string::npos){
					cout<<"a is a string of b"<<endl;
				}
			else{
					cout<<"none of them is a sustring of another"<<endl;
				}
		}
	}
}