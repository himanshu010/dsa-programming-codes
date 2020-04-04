#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

class Car
{
public:
	int x;
	int y;
	int id;
	Car(int x,int y, int id){
		this->x=x;
		this->y=y;
		this->id=id;
	}
	float dist(){
		return sqrt(x*x + y*y);
	}
	void print(){
		float distance= dist();
		cout<<id<<","<<x<<","<<y<<"  :  "<<distance<<endl;
	}

	
};
class Comparator
{
public:
	bool operator()(Car a,Car b){
		return a.dist()>b.dist();
	}
	
};

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
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;\
		int x[]={1,4,3,5,3,8,7,1};
		int y[]={5,4,3,6,1,2,4,6};
		priority_queue<Car,vector<Car>, Comparator> pq;
		for (i=0;i<8;i++){
			Car d(x[i],y[i],i);
			pq.push(d);
		}
		while(!pq.empty()){
			Car r=pq.top();
			r.print();
			pq.pop();
		}

	}
}