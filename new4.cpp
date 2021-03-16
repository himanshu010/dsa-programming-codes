#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n;
    unordered_map<string, int> reversedStrings;
    vector<string> a(n);
    string s;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        a[i] = s;
        reverse(s.begin(), s.end());
        reversedStrings[s]++;
    }

    // In this loop, we are checking that:-
    // 1. If string itself is a Palindrome
    // 2. If reverse of the whole string is present is the array
    for (int i = 0; i < n; ++i)
    {
        if (checkPalindrome(a[i]))
        {
            cout << "true" << endl;
            return 0;
        }
        if (reversedStrings.find(a[i]) != reversedStrings.end())
        {
            cout << "true" << endl;
            return 0;
        }
    }

    // In this for loop we are checking that can a string be divided in a pair of string
    // such that one part of the string is itself a palindrome and the reverse of other part is
    // present in the array
    for (int i = 0; i < n; ++i)
    {
        s = a[i];
        m = s.size();

        // Here we are dividing the array from the front
        // s.substr(0,j) denotes the front part on which we are checking that is a palindrome
        // or not and if it is, then we are checking the the reverse of the rear part(s.substr(j)) is present or not
        for (int j = 1; j < m; ++j)
        {
            if (checkPalindrome(s.substr(0, j)))
            {
                if (reversedStrings.find(s.substr(j)) != reversedStrings.end())
                {
                    cout << "true" << endl;
                    return 0;
                }
            }
        }

        // Here we are dividing the array from the back and are checking using the same procedure as above.
        for (int j = 1; j < m; ++j)
        {
            if (checkPalindrome(s.substr(m - j)))
            {
                if (reversedStrings.find(s.substr(0, m - j)) != reversedStrings.end())
                {
                    cout << "true" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "false" << endl;
}