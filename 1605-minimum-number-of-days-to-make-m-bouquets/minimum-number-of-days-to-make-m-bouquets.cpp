class Solution {
public:
    int possible(vector<int> arr , long long mid , long long m , long long k){
        long long n = arr.size();
        long long cnt =0; 
        long long b =0; 
        for(int i =0; i<n; i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else {
                b+=cnt/k;
                cnt =0;
            }
        }
        b += cnt/k;
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long low =*min_element(bloomDay.begin(), bloomDay.end());
        long long high =*max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;
        long long n = bloomDay.size();
        long long l = (long long) m * k;  
        if(l > n) return -1;

        while(low<=high){
            long long mid = (low+high)/2;
            if(possible(bloomDay ,mid, m , k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
            return ans;
    } 




};