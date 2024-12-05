class Solution {
public:
    int findPeakElement(vector<int>& nums) {
//         // brute force  (Throws error on 2nd test case)
//         int n = nums.size();
//         if(nums[0]>nums[1]) return 0;
//         if(nums[n-1]>nums[n-2]) return n-1;
//         for(int i =1; i<n-1; i++){
//             if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
//                 return i;
//             }
//         }
    
//             //    int low =0; 
//     //    int n  = nums.size();
//     //    int high = n-1;
// return -1;
            int n =nums.size();
            if(n==1) return 0;

            if(nums[0]>nums[1]) return 0;

            if(nums[n-1]>nums[n-2]) return n-1;

            int low =1; int high =n-2; 

            while(low<=high){
                // int mid=low +  high-low/2;
                // int mid = low + high - low / 2;
                int mid = low + (high - low) / 2;



                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid-1]){
                    high =mid-1;
                }
                else if(nums[mid]>nums[mid-1]){
                    low=mid + 1;
                }

            }

        return -1; // will never be executed 
    }
};