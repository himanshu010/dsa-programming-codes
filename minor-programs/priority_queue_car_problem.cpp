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
	Car(int x, int y, int id){
		this->x=x;
		this->y=y;
		this->id=id;
	}
	int dist(){
		return (x*x + y*y);
	}
	void print(){
		cout<<id<<","<<x<<","<<y<<endl;
	}
	
};
class Carcompare
{
public:
	bool operator()(Car a , Car b){
		return a.dist()>b.dist();
	}
	
};

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		int x[]={1,4,3,2,5,6,4,7};
		int y[]={2,4,2,5,3,6,7,2};
		priority_queue<Car, std::vector<Car>,Carcompare> pq;
		for (i=0;i<8;i++){
			Car c(x[i],y[i],i);
			pq.push(c);
		}
		while(!pq.empty()){
			Car p = pq.top();
			p.print();
			pq.pop();
		}

	}
}