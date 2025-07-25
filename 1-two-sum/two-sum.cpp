class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // int ind  = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        // // it will return index with equal to or if equal to this is not present it will return index of greater element than this index
        // int i =0;
        // vector<int> ans;
        // // for(i =0; i<ind; i++){
        // //     int rem = target - nums[i];
        // //     for(int j = i+1; j<ind; j++){
        // //         if(nums[j] == rem ){
        // //             ans.push_back(i);
        // //             ans.push_back(j);
        // //         }
        // //     }
        // // }
        // // return ans;

        // // Brute way to solve this :

        // for(int i =0; i<nums.size(); i++){
        //     if(!ans.empty()) break;
        //     int rem = target-nums[i];
        //     for(int j =i+1; j<nums.size(); j++){
        //         if(nums[j] == rem){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return ans;



        // Optimal Solution : // this is a O(n) complexity solution as here it got return us the answer by lookup in mpp having constant lookup t.c.
        

        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int rem = target - nums[i];
            if(mpp.count(rem)){ // jab count 0 return nhi krega tab true condition hogi and we can enter the loop 
                return {mpp[rem], i}; 
            }
            mpp[nums[i]] =i;
        }
        return {}; // ye possible to nhi h vase but just for our sake 

        
    }
};