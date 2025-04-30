class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int s2=0;
    int s = ((n+1)*n)/2;
    for(int i=0; i<n; i++){
        s2+=nums[i];
    } 
    // return s2; 
    return (s-s2);

    
    }
};