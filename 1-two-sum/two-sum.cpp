class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int , int > mpp;
    int n = nums.size();
    for(int i =0; i<n; i++){
        int num = nums[i];
        int x = target-num ; 
        if(mpp.find(x)!= mpp.end()){
            return{mpp[x],i};
        }
        mpp[num]=i;
    }
    return {-1,-1};
    
    }
}; 