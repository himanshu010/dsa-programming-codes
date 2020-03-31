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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        stack<int>st;
        stack<int>st2;
        cin>>n>>m;
        while(n>0){
            if(n&1){
                st.push(1);
            }
            else {
                st.push(0);
            }
            if(m&1){
                st2.push(1);
            }
            else st2.push(0);

            n=n/10;
            m=m/10;
        }

        while(!st.empty()){
            j=st.top();
            k=st2.top();
            if(j==k){
                cout<<0;
            }
            else cout<<1;
            st.pop();
            st2.pop();
        }
        cout<<endl;
    }
}