class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

       sort(nums.begin(), nums.end()); // Step 1: Sort the array
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int left = lower - nums[i];
            int right = upper - nums[i];
            
            // lower_bound gives first position >= left
            // upper_bound gives first position > right
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), left);
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), right);
            
            count += (it2 - it1); // number of valid j's
        }
        
        return count;}
};