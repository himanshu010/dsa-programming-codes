class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = INT_MAX;
        int res = -1;
        for (int i = 0; i < points.size(); i++) {
            pair<int, int> a = {points[i][0], points[i][1]};
            if (a.first == x or a.second == y) {
                int d = abs(x - a.first) + abs(y - a.second);
                if (d < ans) {
                    res = i;
                    ans = d;
                }
            }
        }
        return res;
    }
};