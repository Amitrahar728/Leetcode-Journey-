class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int even = 0;
        int odd=0;

        for(int i =0; i<nums.size(); i++){
            if(nums[i]<0){
                odd++;
            }
            else if(nums[i]>0){
                even ++;

            }

        }
        return max(odd,even);
    }
};