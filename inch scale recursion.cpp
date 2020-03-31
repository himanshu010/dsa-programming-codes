#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

#define MAX 100000005

int A[MAX];

int Dashnumber = 0;

void PrintDash(int a, int b) {
    for (int i = 0; i < a; ++i)
    {
        cout << '-';
    }
    if (a % b == 0) {
        cout << Dashnumber;
        Dashnumber++;
    }
    cout << endl;
}

void marking(int z, int a, int b, int n) {
    if (z >= b) {
        return;
    }
    int power = pow(2, z);
    // cout << z << "  " << b << "hhhh" << endl << endl;

    for (int i = 0; i < n; i = i + power)
    {
        A[i]++;
    }

    // cout << z << "lllll" << endl;
    marking(z = z + 1, a, b, n);


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
        int i = 0, j, k, a, b, m, ans = 0, cnt = 0, sum = 0;
        cin >> a >> b;

        int n = a * (pow(2, b - 1) + 1) - (a - 1);
        // vector<int> totalMarks(n);
        int z = 0;
        marking(z, a, b, n);
        while (A[i] != 0) {
            PrintDash(A[i], b);
            i++;
        }
    }
}