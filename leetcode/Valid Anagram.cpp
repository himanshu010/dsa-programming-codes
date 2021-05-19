class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26, 0), b(26, 0);

        for (auto x : s) {
            a[(int)x - 'a'] += 1;
        }
        for (auto x : t) {
            b[(int)x - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
    }
};