#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int x,y;

int gcd(int a,int b){
    if(b==0){
        return a;
    }

    int ans=gcd(b,a%b);
    if(ans==1){
        return 1;
    }
    else{
        return 0;
    }
    // return ans;
}


void extendedEuclidTheorem(int a, int b){
    if(b==0){
        x=1;
        y=0;
        return;
    }

    extendedEuclidTheorem(b,a%b);
    int current_X=y;
    int current_y=x-(a/b)*y;
    x=current_X;
    y=current_y;
    // cout<<x<<endl;
    x=(x+b)%b;
    // cout<<x<<endl;

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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0, a, b;
        cin>>a>>m;
        //Form the equation ab+m(-k)=1
        //therefore GCD(a,m) should be 1(Extended Eucledian Theorem)

        ans=gcd(a,m);
        // cout<<ans;
        if(ans==1){
        extendedEuclidTheorem(a,m);
            cout<<"b= "<<x<<endl<<"-k= "<<y<<endl;
        }
        else{
            cout<<"modulo inverse not exist"<<endl;
        }


    }
}