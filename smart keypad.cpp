#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

char table[][100] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(char n[], char out[], int i, int j)
{
    if (n[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    int digit = n[i] - '0';
    for (int k = 0; table[digit][k] != '\0'; k++)
    {
        out[j] = table[digit][k];
        keypad(n, out, i + 1, j + 1);
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, k, m, ans = 0, cnt = 0, sum = 0;
    // cin >> n;

    // int t;cin>>t;while(t--)
    {
        char n[100];
        cin >> n;
        char out[100];
        keypad(n, out, 0, 0);
    }
}