class Solution {
public:

    bool check(int* a, int n, int sum) {
        if (n == 0 and sum != 0) {
            return false;
        }
        if (sum == 0) {
            return true;
        }
        if (a[n - 1] <= sum) {
            return check(a, n - 1, sum - a[n - 1]) || check(a, n - 1, sum);
        }
        else {
            return check(a, n - 1, sum);
        }
    }
    int equalPartition(int n, int a[])
    {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += a[i];
        }
        if (total & 1) {
            return false;
        }

        if (check(a, n, total / 2)) {
            return 1;
        }
        return 0;
    }
};