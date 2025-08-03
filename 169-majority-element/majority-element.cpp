class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // int i =0;
        int maxi =0;
        int local = 1;
        for(int i =0; i<n-1; i++){
            if(nums[i]!=nums[i+1]){
                maxi = max(maxi, local);
                local = 1;
                if(maxi>n/2) return nums[i];

            }
            else {
                local ++;
            }

        }
        return nums[n-1];
    }
};