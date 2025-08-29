class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0; int r =0; 
        long long  sum =0;
        int min_length = INT_MAX;
        int len ;
        while(r<nums.size()){
            sum+=nums[r];
            
            while(sum>=target){
                min_length = min(min_length , r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(min_length == INT_MAX) return 0;
        else return min_length;
    }
};