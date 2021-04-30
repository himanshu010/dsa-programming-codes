class Solution {
public:
	int AlternatingaMaxLength(vector<int>&a) {
		int n = a.size();
		int inc = 1, dec = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				inc = dec + 1;
			}
			else if (a[i] < a[i - 1]) {
				dec = inc + 1;
			}
		}

		return max(inc, dec);
	}

};