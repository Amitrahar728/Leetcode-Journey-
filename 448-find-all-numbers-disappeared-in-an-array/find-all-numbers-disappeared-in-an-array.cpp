class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i =0 ;i<n+1; i++){
            mpp[i] = 0;
        }
        sort(nums.begin() , nums.end());
        vector<int> arr;
        for(int x: nums){
            mpp[x]++;
        }
        for(auto const& [k,v] : mpp){
            if(k !=0 && v ==0){
                arr.push_back(k);
            }
        }
        return arr;
        
    }
};