class Solution {
public:
    bool squareIsWhite(string s) {
        char c = s[0];
        int n = s[1];

        if ((int)(c - 'a') & 1) {
            if (n & 1) {
                return true;
            }
            return false;
        }
        else {
            if (n & 1) {
                return false;
            }
            return true;
        }
    }
};