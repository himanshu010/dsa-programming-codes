class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> a(num + 1);
		for (int i = 0; i <= num; i++) {
			a[i] = a[i >> 1] + (i & 1);
		}
		return a;
	}
};