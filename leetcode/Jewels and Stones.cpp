class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        sort(jewels.begin(), jewels.end());
        sort(stones.begin(), stones.end());

        int i = 0, j = 0;
        int sum = 0;
        int n = jewels.size();
        int m = stones.size();
        while (i < n and j < m) {
            if (jewels[i] == stones[j]) {
                sum += 1;
                j += 1;
            }
            else if (jewels[i] < stones[j]) {
                i++;
            }
            else {
                j++;
            }

        }

        return sum;
    }
};