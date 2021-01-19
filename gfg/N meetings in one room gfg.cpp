#define P pair<int, int>
#define F first
#define S second

bool compare(P a, P b)
{
    return a.S < b.S;
}

int maxMeetings(int start[], int end[], int n)
{
    int sum = 1;
    vector<P> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = {start[i], end[i]};
    }

    sort(a.begin(), a.end(), compare);
    int last = a[0].S;
    for (int i = 1; i < n; i++)
    {
        if (a[i].F > last)
        {
            last = a[i].S;
            sum += 1;
        }
    }

    return sum;
}