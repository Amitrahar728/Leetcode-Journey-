#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> ps(nums.size());
        ps[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ps[i] = ps[i-1] + nums[i];
        }

        int mx = nums[0];
        int mn = 0;

        for (int i = 0; i < ps.size(); ++i) {
            mx = max(mx, ps[i] - mn);
            mn = min(mn, ps[i]);
        }
        return mx;
    }
};