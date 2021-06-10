class Solution
{
  public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int maxEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        sort(events.begin(), events.end(), compare);
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int d = 0;
        int ans = 0;
        while (i < n or !pq.empty())
        {
            if (pq.empty() and i < n)
            {
                d = events[i][0];
            }
            while (i < n and events[i][0] <= d)
            {
                pq.push(events[i][1]);
                i++;
            }
            if (!pq.empty())
            {
                ans += 1;
                pq.pop();
            }
            d += 1;
            while (!pq.empty() and pq.top() < d)
            {
                pq.pop();
            }
        }
        return ans;
    }
};