class Solution {
public:
    int max_Books(int a[], int n, int k)
    {
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > k) {
                sum = 0;
            }
            else {
                sum += a[i];
            }
            ans = max(ans, sum);
        }

        return ans;

    }
};