vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
	long long prod = 1;
	int zeroFlag = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] != 0) {
			prod *= nums[i];
		}
		else {
			zeroFlag += 1;
		}
	}

	if (zeroFlag > 1) {
		for (int i = 0; i < n; i++) {
			nums[i] = 0;
		}
		return nums;
	}
	if (zeroFlag == 1) {
		for (int i = 0; i < n; i++) {
			if (nums[i] != 0) {
				nums[i] = 0;
			}
			else {
				nums[i] = prod;
			}
		}
		return nums;
	}
	for (int i = 0; i < n; i++) {
		nums[i] = prod / nums[i];
	}
	return nums;
}