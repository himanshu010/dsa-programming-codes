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
		priority_queue<int> pq_max;
		pq_max.push(1);
		pq_max.push(5);
		pq_max.push(7);
		pq_max.push(9);
		pq_max.push(10);
		pq_max.push(5);
		pq_max.push(6);
		while(!pq_max.empty()){
			cout<<pq_max.top()<<",";
			pq_max.pop();
		}
	}
}