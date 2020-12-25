#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back

int sum = 0;

bool isSafe(int board[][10], int i, int j, int n)
{
    // You can check col
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }
    // For checking left diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    // For checking right diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    // Position is now safe
    return true;
}

bool solveQueen(int board[][10], int i, int n)
{
    // Base Case
    if (i == n)
    {
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            cout << "\"";
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q";
                }
                else
                {
                    cout << ".";
                }
            }
            if (i != n - 1)
            {
                cout << "\"" << endl;
            }
            else
            {
                cout << "\"]" << endl;
            }
        }
        cout << endl;
        // sum++;
        return false;
    }
    // Recursive Case
    // Try to place the Queen in the current row and call on the remaining part
    // which will be solved by recursion.
    for (int j = 0; j < n; j++)
    {
        // I have to check if i,j is safe to place the queen or not
        if (isSafe(board, i, j, n))
        {
            // Place the queen;
            board[i][j] = 1;
            bool nextQueenCanBePlaced = solveQueen(board, i + 1, n);
            if (nextQueenCanBePlaced)
            {
                return true;
            }
            // Means i,j is not the right position-assumption is wrong
            board[i][j] = 0;
        }
    }
    return false;
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

    int i, j, k, n, m, ans = 0, cnt = 0;
    cin >> n;

    // int t;cin>>t;while(t--)
    {
        int board[10][10] = {0};
        solveQueen(board, 0, n);
        // cout << sum;
    }
}

// #include<bits/stdc++.h>

// using namespace std;

// #define int long long int
// #define ld long double
// #define F first
// #define S second
// #define P pair<int,int>
// #define pb push_back

// int sum = 0;

// bool canPlace(int board[][10], int i, int j, int n) {
// 	int x = i;
// 	int y = j;
// 	for (int row = 0; row <= x; ++row)
// 	{
// 		if (board[i - row][j]) {
// 			return false;
// 		}
// 	}
// 	while (x >= 0 && y >= 0) {
// 		if (board[x][y]) {
// 			return false;
// 		}
// 		x--;
// 		y--;
// 	}
// 	x = i;
// 	y = j;
// 	while (x >= 0 && y < n) {
// 		if (board[x][y]) {
// 			return false;
// 		}
// 		x--;
// 		y++;
// 	}
// 	return true;
// }

// bool solveQueen(int board[][10], int i, int n) {

// 	//Base Case
// 	if (i == n) {
// 		//cout<<board;
// 		// for (int i = 0; i < n; i++) {
// 		// 	for (int j = 0; j < n; j++) {
// 		// 		if (board[i][j] == 1) {
// 		// 			cout << "Q ";
// 		// 		}
// 		// 		else {
// 		// 			cout << ". ";
// 		// 		}

// 		// 	}
// 		// 	cout << endl;
// 		// }
// 		// cout << endl;
// 		sum++;
// 		return false;
// 	}

// 	//recursive case

// 	for (int j = 0; j < n; ++j)
// 	{
// 		if (canPlace(board, i, j, n)) {
// 			board[i][j] = 1;
// 			bool solved = solveQueen(board, i + 1, n);
// 			if (solved) {
// 				return true;
// 			}
// 		}

// 		board[i][j] = 0;
// 	}
// 	return false;

// }

// int32_t main()
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r" , stdin);
// 	freopen("output.txt", "w" , stdout);
// #endif

// 	ios_base:: sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// 	int i, j, k, n, m, ans = 0, cnt = 0;
// 	cin >> n;

// 	// int t;cin>>t;while(t--)
// 	{
// 		int board[10][10] = {0};

// 		solveQueen(board, 0, n);
// 		cout << sum;
// 	}
// }