class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum =nums[0];
        int maxsum =sum;
        bool check = true;
       for(int i =0; i<nums.size()-1; i++){
           if(nums[i] <nums[i+1]){
                sum+=nums[i+1];
                if(sum>maxsum){
                    check = false;
                    maxsum = sum;
                }
           }
           else sum =nums[i+1];
       } 
       if(check == false)
       return maxsum;
       else return nums[0];
    }
};