#define P pair<int,int>
#define F first
#define S second


bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> JobScheduling(Job arr[], int n)
{
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        mx = max(mx, arr[i].dead);
    }
    sort(arr, arr + n, compare);

    vector<P> a(mx + 1);
    for (int i = 0; i <= mx; i++) {
        a[i] = { -1, 0};
    }
    for (int i = 0; i < n; i++) {
        int j = arr[i].dead;
        while (j > 0) {
            if (a[j].F == -1) {
                a[j].F = arr[i].id;
                a[j].S = arr[i].profit;
                break;
            }
            j--;
        }
    }

    int count = 0;
    int sum = 0;

    for (auto x : a) {
        if (x.F != -1) {
            count += 1;
            sum += x.S;
        }
    }

    return {count, sum};
}