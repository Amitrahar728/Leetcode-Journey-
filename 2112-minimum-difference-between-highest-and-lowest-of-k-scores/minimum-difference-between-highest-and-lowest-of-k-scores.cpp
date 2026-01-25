class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() ,nums.end());
        int n =nums.size();
        if(n ==1) return 0;
        int mini= INT_MAX;
        int i =0; 
        while(i<n-k+1){
            int diff = nums[i+k-1]-nums[i];
            mini = min(mini , diff);
            i++;
        }
        return mini;
    }
};