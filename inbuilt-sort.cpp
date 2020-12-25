#include <bits/stdc++.h>

#include <iostream>
using namespace std;
bool mycompare(int a, int b)
{
    cout << "compare :" << a << "and" << b << "\n";
    return b < a;
}
int main()
{
    int s;
    cin >> s;
    int a[] = {1, 4, 7, 5, 4, 5, 6, 7, 3, 66, 5, 4, 55, 4};
    int n = sizeof(a) / sizeof(int);
    sort(a, a + n, mycompare);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
