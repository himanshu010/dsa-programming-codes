class Solution
{
  public:
    int l = INT_MAX, r = INT_MIN;

    void binarySearchLeft(vector<int> &a, int t, int s, int e, int n)
    {
        if (s > e)
        {
            return;
        }
        if (s == e)
        {
            if (a[s] == t)
            {
                l = min(l, s);
            }
            return;
        }

        int mid = s + (e - s) / 2;

        if (a[mid] == t)
        {
            l = min(l, mid);
            binarySearchLeft(a, t, s, mid - 1, n);
        }
        if (a[mid] > t)
        {
            binarySearchLeft(a, t, s, mid - 1, n);
        }
        if (a[mid] < t)
        {
            binarySearchLeft(a, t, mid + 1, e, n);
        }
    }

    void binarySearchRight(vector<int> &a, int t, int s, int e, int n)
    {
        if (s > e)
        {
            return;
        }
        if (s == e)
        {
            if (a[s] == t)
            {
                r = max(r, s);
            }
            return;
        }

        int mid = s + (e - s) / 2;

        if (a[mid] == t)
        {
            r = max(r, mid);
            binarySearchRight(a, t, mid + 1, e, n);
        }
        if (a[mid] > t)
        {
            binarySearchRight(a, t, s, mid - 1, n);
        }
        if (a[mid] < t)
        {
            binarySearchRight(a, t, mid + 1, e, n);
        }
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        binarySearchLeft(nums, target, 0, n - 1, n);
        if (l == INT_MAX)
        {
            return {-1, -1};
        }

        binarySearchRight(nums, target, 0, n - 1, n);
        return {l, r};
    }
};