class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high =n-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        int index = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        return index;
    }
};