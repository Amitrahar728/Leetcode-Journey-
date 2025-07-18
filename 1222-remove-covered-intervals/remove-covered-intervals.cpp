class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0, right = 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        for (int i = 0, n = intervals.size(); i < n; ++i) {
            if (intervals[i][1] > right) {
                right = intervals[i][1];
                ++res;
            }
        }
        return res;
    }
};