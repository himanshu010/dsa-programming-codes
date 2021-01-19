bool compare(val a, val b) {
    return a.second < b.second;
}

int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, compare);
    vector<int> mx(n, 1);
    int mm = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (p[i].first > p[j].second) {
                if (mx[i] < mx[j] + 1) {
                    mx[i] = mx[j] + 1;
                }
            }
        }
    }

    for (auto x : mx) {
        mm = max(x, mm);
    }
    return mm;
}