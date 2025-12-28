class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt =0;
        int cnt =0;
        for(int x : nums){
            if(x == 1){
                cnt++;
                maxcnt = max(maxcnt , cnt );
            }
            else{
                cnt =0;
            }
        }
        return maxcnt;
    }
};