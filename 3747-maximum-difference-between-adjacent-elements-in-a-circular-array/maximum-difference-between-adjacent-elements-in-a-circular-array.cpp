class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        vector<int> arr;
        for(int i =0; i<nums.size(); i++){
            arr.push_back(nums[i]);
        }
        for(int i =0; i<nums.size(); i++){
            arr.push_back(nums[i]);
        }
        int mini = INT_MIN;
        for(int i =1; i<arr.size(); i++){
            if(abs(arr[i]-arr[i-1])>mini){
                mini = abs(arr[i]-arr[i-1]);
            }
        }
        return mini;
    }
};