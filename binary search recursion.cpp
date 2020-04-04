#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

int ans;
int BinarySearch(int A[], int start, int end, int n) {

    int len = end - start;
    int pos = start + (len / 2);
    cout << start << " " << pos << " " << end << endl;
    if (len / 2 == 0) {
        cout << "Not Found---------------" << endl;
        ans = -1;
        return ans;
    }
    if (n == A[pos]) {
        cout << "middle" << endl;
        ans = pos;
        return ans;
    }
    if (n == A[start]) {
        cout << "start" << endl;
        ans = start;
        return ans;
    }
    if (n == A[end]) {
        cout << "end" << endl;
        ans = end;
        return ans;
    }

    if (n > A[pos]) {
        cout << "second-half-again" << endl;
        BinarySearch(A, pos, end, n);
    }
    if (n < A[pos]) {
        cout << "first-half-again" << endl;
        BinarySearch(A, start, pos, n);
    }
    return ans;
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
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        sort(A, A + n);
        cin >> m;
        int f = BinarySearch(A, 0, n - 1, m);
        cout << "index: " << f ;

    }
}