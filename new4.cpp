void solve(int tc)
{

    int a, b, k;
    cin >> a >> b >> k;

    vi boys(k);
    vi girls(k);

    for (int i = 0; i < k; i++)
        cin >> boys[i];

    for (int i = 0; i < k; i++)
        cin >> girls[i];

    vector<int> graph1[a + 5];
    vector<int> graph2(b + 5, 0);

    for (int i = 0; i < k; i++)
    {
        graph1[boys[i]].pb(girls[i]);
        graph2[girls[i]]++;
    }

    vi suffix(a + 5, 0);
    suffix[a] = graph1[a].size();
    for (int i = a - 1; i > 0; i--)
    {
        suffix[i] = suffix[i + 1] + graph1[i].size();
    }

    int ans = 0;
    for (int i = 1; i <= a; i++)
    {

        for (auto j : graph1[i])
        {
            int temp = graph2[j] - 1;
            ans += suffix[i + 1] - temp;
            graph2[j]--;
        }
    }
    cout << ans << endl;
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