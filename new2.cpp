
void solve(int tc) {



	int n, k;
	cin >> n >> k;
	if (k < n)
	{

		int o = n / k;
		if (n % k != 0)
			k = (o + 1) * k;
		else
			k = n;

	}


	int x = k / n;
	if (k % n != 0)
		x++;

	cout << x << endl;
	R;



















}


int32_t main()
{




#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);




	int t = 1;

	cin >> t;
	int tc = 1;




	while (t--)
	{

		solve(tc);


		tc++;
	}
	return 0;
}