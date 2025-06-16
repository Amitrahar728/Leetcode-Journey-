class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = INT_MIN;
        bool check = true;
        for(int i =0; i<nums.size(); i++){
            for(int j =i+1; j<nums.size(); j++){
                if(nums[i]<nums[j]){
                    check = false;
                int diff = nums[j]-nums[i];
                maxi = max(diff, maxi);
                }
            }
        }
        if(check == true ) return -1;
        return maxi;
    }
};