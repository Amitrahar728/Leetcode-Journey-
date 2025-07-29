class Solution {
public:
    int cnti (int n ){
        int cnt =0;
        while(n>0){
            int rem = n%10;
            n = n/10;
            cnt++;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int final =0;
        for(int i =0; i<n; i++){
            if(cnti(nums[i])%2 ==0){
                final++;
            }
        }
        return final;
    }
};