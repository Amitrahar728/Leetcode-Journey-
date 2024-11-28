class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool check = true;
        for(int i=0 ; i<nums.size(); i++){
      
            if(nums[i]== target){
                check = false;
                return i ;
                
            }
        }
        return -1;
    }
};