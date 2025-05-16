class Solution {
public:
    int func(vector<int> nums , int k){
        if(k<0) return 0;
        int l =0; int r =0;
        int sum =0;
        int cnt =0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>k){
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r=r+1;

        }return cnt ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%2 ==0) nums[i]=0;
            else nums[i]=1;
        }
        return  func(nums,k)-func(nums,k-1);
    }
};
