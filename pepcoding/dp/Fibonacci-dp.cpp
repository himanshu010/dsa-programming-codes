#include <iostream>
using namespace std;

int fib(int n)
{
    // write your code here
    int a = 0;
    int b = 1;
    if (n <= 1)
    {
        return n;
    }
    int c;
    n -= 1;
    while (n--)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}