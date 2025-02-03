class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt  =1;
        int cnt2 =1;
        int maxLen = 1;
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]){
                cnt++;
            }
            else{
                cnt =1;
            }
            maxLen = max(maxLen, cnt);
        }
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                cnt2++;
            }
            else {
                cnt2 = 1 ;
            }
            maxLen = max(maxLen, cnt2);
        }
        // cout<<cnt<<cnt2<<endl;
        return maxLen;
    }
};