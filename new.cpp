#include<bits/stdc++.h>
#define moduli  998244353
#define int long long int

#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return


using namespace std;
int  C(int n, int r)
{
  if (r > n - r)
    r = n - r;
  int  ans = 1;


  for (int i = 1; i <= r; i++) {
    ans *= ( n - r + i);
    ans /= i;
  }

  return ans;
}


int stringtointer(string a)
{

  return stoi(a);
}
int countdigit(int a)
{

  int ans = 0;

  while (a)
  {
    a /= 10;
    ans++;
  }


  return ans;
}


int factorial(int n)
{

  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
int dayofweek(int d, int m, int y)
{
  static int t[] = { 0, 3, 2, 5, 0, 3,
                     5, 1, 4, 6, 2, 4
                   };
  y -= m < 3;
  return ( y + y / 4 - y / 100 +
           y / 400 + t[m - 1] + d) % 7;
}
int floorSqrt(int x)
{

  if (x == 0 || x == 1)
    return x;
  int start = 1, end = x, ans;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    if (mid * mid == x)
      return mid;
    if (mid * mid < x)
    {
      start = mid + 1;
      ans = mid;
    }
    else
      end = mid - 1;
  }

  return ans;
}



bool checkpallindrome(string s)
{


  string ans = s;

  reverse(ans.begin(), ans.end());

  if (ans == s)
    return true;


  return false;

}

int kadane(int a[], int size)
{
  int max_so_far = INT_MIN, max_ending_here = 0;

  for (int i = 0; i < size; i++)
  {
    max_ending_here = max_ending_here + a[i];
    if (max_so_far < max_ending_here)
      max_so_far = max_ending_here;

    if (max_ending_here < 0)
      max_ending_here = 0;
  }
  return max_so_far;
}



int calc(int x, int y)
{
  int res = 1;

  x = x  ;

  if (x == 0) return 0;

  while (y > 0)
  {

    if (y & 1)
      res = (res * x % moduli) % moduli ;


    y = y >> 1;
    x = (x % moduli * x % moduli) % moduli;
  }


  return res;

}


int gcdExtended(int a, int b, int *x, int *y)
{
  // Base Case
  if (a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }

  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);


  *x = y1 - (b / a) * x1;
  *y = x1;

  return gcd;
}

// Function to find modulo inverse of a
int modInverse(int a, int m)
{
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  int res = (x % m + m) % m;
  return  res;


}

int lps[1000001];
void computelps(string s)
{

  lps[0] = 0;
  int len = 0;
  int i = 1;
  int n = s.size();
  while (i < n)
  {

    if (s[len] == s[i])
    {


      len++;
      lps[i] = len;
      if (i != n - 1) {
      }

      i++;
    }
    else {


      if (len != 0)
        len = lps[len - 1];
      else {

        lps[i] = 0;
        i++;
      }


    }

  }



}

void solve(int tc)
{

  int n; cin >> n;
  int k; cin >> k;

  int arr[n];
  bool visited[n];

  memset(visited, false, sizeof(visited));



  for (int i = 0; i < n; i++)
    cin >> arr[i];


  for (int i = 0; i < n - k; i++)
  {
    if (visited[i])
      continue;

    vector<int>op;
    for (int j = i; j < n; j += k)
    {

      op.pb(arr[j]);
      visited[j] = true;

    }


    sort(op.begin(), op.end());
    int f = 0;
    for (int j = i; j < n; j += k)
    {


      arr[j] = op[f];
      f++;

    }

  }
// for(int i=0;i<n;i++)
// {
//   cout<<arr[i]<<" ";
// }
//cout<<endl;
  for (int i = 1; i < n; i++)
  {

    if (arr[i] < arr[i - 1])
    {
      cout << "no" << endl;
      R;
    }
  }

  cout << "yes" << endl;
  R;


}

//ii===888

int32_t main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


  ios_base::sync_with_stdio(false);
  cin.tie(NULL);




  int t = 1;
  // cin >> t;
  // while (t--)
  int tc = 1;
  {

    solve(tc);

    // for(int i=0;i<=1e6;i++)
    // graph[i].clear();
    tc++;



  }
  return 0;
}