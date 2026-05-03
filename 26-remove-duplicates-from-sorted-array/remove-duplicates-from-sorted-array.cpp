class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0 ; int j =1; 
        int k = 1; 
        while(i< nums.size() && j <nums.size()){
            if(nums[j]== nums[i]){
                j++;
            }
            else if(nums[j]!= nums[i]){
                i++;
                k++;
                nums[i] = nums[j];
                j++;
            }

        }
        return k ; 
    }
};