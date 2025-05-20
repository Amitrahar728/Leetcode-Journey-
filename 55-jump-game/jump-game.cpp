class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind =0;
        if(nums.size()==1) return true;
        for(int  i = 0; i<nums.size(); i++){
            if(maxind<i){
                return false;
            }
            
               maxind = max(maxind, i + nums[i]);
            
            if(maxind>=nums.size()-1){
                break;
            }
        }
        if(maxind>=nums.size()-1){
            return true;
        }
        else return false;
    }
};