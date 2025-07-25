class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // int ind  = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        // // it will return index with equal to or if equal to this is not present it will return index of greater element than this index
        // int i =0;
        vector<int> ans;
        // for(i =0; i<ind; i++){
        //     int rem = target - nums[i];
        //     for(int j = i+1; j<ind; j++){
        //         if(nums[j] == rem ){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;


        for(int i =0; i<nums.size(); i++){
            if(!ans.empty()) break;
            int rem = target-nums[i];
            for(int j =i+1; j<nums.size(); j++){
                if(nums[j] == rem){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
        
    }
};