class Solution
{
  private:
    vector<int> tree = vector<int>(400005);
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }
    void buildTree(int s, int e, int index)
    {
        if (s == e)
        {
            tree[index] = s;
            return;
        }

        int mid = s + (e - s) / 2;
        buildTree(s, mid, 2 * index + 1);
        buildTree(mid + 1, e, 2 * index + 2);

        tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }

    int queryDay(int s, int e, int l, int r, int index)
    {
        if (l > e or r < s)
        {
            return INT_MAX;
        }

        if (l <= s and r >= e)
        {
            return tree[index];
        }

        int mid = s + (e - s) / 2;
        return min(queryDay(s, mid, l, r, 2 * index + 1), queryDay(mid + 1, e, l, r, 2 * index + 2));
    }

    void updateTree(int s, int e, int d, int index)
    {
        if (d < s or d > e)
        {
            return;
        }
        if (s == e)
        {
            tree[index] = INT_MAX;
            return;
        }
        int mid = s + (e - s) / 2;

        updateTree(s, mid, d, 2 * index + 1);
        updateTree(mid + 1, e, d, 2 * index + 2);
        tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }

  public:
    int maxEvents(vector<vector<int>> &events)
    {
        buildTree(1, 100000, 1);
        int ans = 0;
        sort(events.begin(), events.end(), compare);
        for (auto x : events)
        {
            int day = queryDay(1, 100000, x[0], x[1], 1);
            if (day != INT_MAX)
            {
                ans += 1;
                updateTree(1, 100000, day, 1);
            }
        }
        return ans;
    }
};