class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // int cnt =0;
       for(int i =0; i<nums.size()-1; i++){
            if((nums[i]%2  == nums[i+1]%2)){
                // check = false;
                return false;
            }
       }  
       return true;
    }
};