class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans = nums;

    int ind = 0;
    for (int k = 0; k < n; k++) {
        ans[ind] = nums[k];
        ans[ind+1] = nums[k+n];
        ind += 2;
    }
    return ans;
    }
};