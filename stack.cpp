#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        stack<string> st;
        st.push("mango");
        st.push("apple");
        st.push("pineapple");
        st.push("guava");
        st.push("carrot");
        while (!st.empty())
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
}