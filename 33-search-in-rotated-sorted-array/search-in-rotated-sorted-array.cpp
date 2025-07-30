// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int low =0;
//         int high = n-1;
//         while(low<=high){
//             int mid = low-(high+low)/2;
//             if(target == nums[mid]) return mid;
//             else if(nums[low]<=nums[mid]){
//                 if(target<=nums[mid] && nums[low]<=target){
//                 high = mid-1;
//                 }
//                 else{
//                     low = mid+1;
//                 }

//             }
//             else{
//                 if(target<=nums[high] && nums[mid]<=target){
//                 low = mid+1;
//                 }
//                 else{
//                    high = mid-1;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low+(high-low)/2;
            if (nums[mid] == target) return mid;

             if(nums[low] <= nums[mid]){
                 if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else { 
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
    }
};