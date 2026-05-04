class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefixsum(nums.size());
        prefixsum[0] =nums[0];
        for(int i =1; i<nums.size(); i++){
            prefixsum[i] = prefixsum[i-1]+nums[i];
        }

        //  at any point sum = Prefix(r) - prefix(l-1) 
        //  for maximizing this prefix(l-1) should be minimized, for minimizing it 
        int ans = prefixsum[0];
        
        int mini =0;
        for(int i=0; i<prefixsum.size(); i++){
            int besttillnow = prefixsum[i]- mini;
            mini = min(mini , prefixsum[i]);
            ans = max(ans , besttillnow);
        }
        return ans;
    }
};