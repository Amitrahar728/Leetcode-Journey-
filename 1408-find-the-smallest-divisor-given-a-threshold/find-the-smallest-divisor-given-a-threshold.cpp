class Solution {
public:
    int div(vector<int> arr, int mid , int limit){
        int n = arr.size();
        int sum =0; 
        for(int i =0 ; i<n ; i++){
            sum+=ceil((double)arr[i]/double(mid));

        }
        return sum<=limit;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int n = nums.size();
        int high =*max_element(nums.begin(), nums.end());
        // int ans =high;
        if (n > threshold) return -1;
        while(low<=high){
            int mid =(low+high)/2;
            if(div(nums,mid,threshold)){
                high = mid -1;
                // ans = mid;
            }
            else low = mid+1;
        }
        return low;
    }

};