class NumArray
{
  public:
    vector<int> a;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> b(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            this->a.push_back(sum);
        }
        // for(auto x: a){
        //     cout<<x<<' ';
        // }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return a[right];
        }
        return a[right] - a[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */