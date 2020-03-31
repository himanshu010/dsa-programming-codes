#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

class employee
{
public:
    string name;
    int sal;
    employee(string name, int sal){
        this->name=name;
        this->sal=sal;
    }
    // int sal(){
    //     return sal;
    // }
    void print(){
        cout<<name;
        cout<<" "<<sal<<endl;
    }
    
};
class compare
{
public:
    bool operator()(employee a, employee b){
        if (a.sal==b.sal){
            return a.name>b.name;
        }
        else{
            return a.sal<b.sal;
        }
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0,sal;
        string name;
        priority_queue<employee,std::vector<employee>,compare> pq;
        cin>>n;
        cin>>m;
        for (int i = 0; i < m; ++i)
        {
            cin>>name;
            cin>>sal;
            if(sal>=n&&sal<=100){
                employee c(name,sal);
                pq.push(c);
            }
            
        }
        while(!pq.empty())
            {
                employee d=pq.top();
                d.print();
                pq.pop();
            }
    }
}