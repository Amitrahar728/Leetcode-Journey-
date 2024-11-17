class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> arr(2,-1);
        
    auto  l = lower_bound(nums.begin(), nums.end(), target);
    
    if (l == nums.end() || *l != target) {
            return arr; 
    }
    
    auto u =upper_bound(nums.begin(), nums.end(), target);
    

    arr[0] = l - nums.begin(); 
        arr[1] = u- nums.begin() -1; 


    return arr;
    }

};