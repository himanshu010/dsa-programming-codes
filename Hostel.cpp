#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

class Hostel
{
    public:
    int x,y;
    Hostel(int x,int y){
        this->x=x;
        this->y=y;
    }
    int rd(){
        int x=this->x;
        int y=this->y;
        return (x*x+y*y);
    }
    void show(){
        int dist=rd();
        cout<<dist<<endl;
    }
    
};
class Compare
{
public:
    bool operator()(Hostel b,Hostel c){
    return b.rd()>c.rd();
}    
};


int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {

        int a,b,c,i, j, k, n, m, ans = 0, cnt = 0, sum = 0,q;
        cin>>q>>k;
        priority_queue<Hostel, std::vector<Hostel>, Compare> pq;
        // queue<int> qu;
        for (int i = 0; i < q; ++i)
        {
            cin>>a;
            if (a==1){
                cin>>b>>c;
                Hostel h(b,c);
                pq.push(h);
            }
            else{
                Hostel nearest=pq.top();
                nearest.show();
            }
        }
    }
}