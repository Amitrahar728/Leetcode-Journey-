class Solution {
public:
    int day(vector<int> arr , int cap){
        int day =1;
        int load =0;
        int n = arr.size();
        for(int i =0; i<n; i++){
            if((load+arr[i])>cap){
                day+=1;
                load = arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        return day;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low =*max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            // int mid = (low+high)/2;
            int mid = low + (high - low) / 2;

            if(day(weights,mid)<=days){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};