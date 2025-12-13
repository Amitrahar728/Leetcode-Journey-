class Solution {
public:
    bool check(int mid , vector<int>  arr, int m , int k ){
        int cnt =0;
        int ans =0;
        for(int i =0; i<arr.size(); i++){
            if(arr[i]<= mid){
                cnt++;
                if(cnt == k){
                    cnt =0;
                    ans++;
                    if(ans == m){
                        return true;
                        
                    }
                }
            }
            else{
                cnt =0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long mul = (long long)m*k;
        if(bloomDay.size() < mul){
            return -1;
        }
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid, bloomDay, m , k)){
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