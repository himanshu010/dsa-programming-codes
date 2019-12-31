#include <iostream>
#include <bits/stdc++.h>
int n = 20;
int A[20];
int thrice;
int sum;
using namespace std;
int main()
{
    cout << "\nEnter the numbers in the array:-\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    thrice = n / 3;

    sort(A, A + n);
    cout << "sorted\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\n";
    }
    cout << "\nanswer array\n";
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        if (A[i] != A[i + 1])
        {
            // cout << A[i];
            for (int j = 0; j < n; j++)
            {
                if (A[i] == A[j])
                {
                    sum++;
                }
            }
            cout << A[i] << ":" << sum << "\n";
            if (sum > thrice)
            {
                cout << A[i] << "\n";
            }
            else
            {
                cout << "-1"
                     << "\n";
            }
        }
    }

    return 0;
}