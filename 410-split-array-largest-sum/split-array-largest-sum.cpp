class Solution {
public:
int cnt(vector<int> arr, int m ){
    int painter = 1 ;
    long long color = 0;
    for(int i = 0 ; i<arr.size(); i++){
        if(color + arr[i] <= m ){
            color+=arr[i];
        }
        else{
            painter +=1;
            color = arr[i];
        }
    }
    return painter;
}



    int splitArray(vector<int>& nums, int k) {
        int  n = nums.size();
   if(k>n) return -1;
   int low = *max_element(nums.begin(), nums.end());
   int high = accumulate(nums.begin(), nums.end(),0);
   while(low<=high){
       int mid=(low+high)/2;
       int total=cnt(nums,mid);
    if(total > k ) low = mid+1;
    else high = mid -1;
       

   }
   return low;

    }
};