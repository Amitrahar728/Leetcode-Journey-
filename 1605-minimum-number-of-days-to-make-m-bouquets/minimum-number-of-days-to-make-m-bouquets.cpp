class Solution {
public:
    bool check(int mid , vector<int>  arr, int m , int k ){
        for(int i =0; i<arr.size(); i++){
            arr[i] = arr[i]-mid;
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
        int cnt =0;
        int ans =0;
        for(int i =0; i<arr.size(); i++){
            if(arr[i]<= 0){
                cnt++;
                if(cnt == k){
                    cnt =0;
                    ans++;
                    if(ans == m){
                        // cout<<"NOW I AM RETURNING TRUE";
                        // cout<<endl;
                        return true;
                        
                    }
                }
            }
            else{
                cnt =0;
            }
            // cout<<ans<<" ";
        }
        // cout<<endl;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long mul = (long long)m*k;
        if(bloomDay.size() < mul){
            return -1;
        }
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        // cout<<low<<" "<<high<<endl;
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            // cout<<"low"<<"->"<<low<<endl;
            // cout<<"high"<<"->"<<high<<endl;
            // cout<<mid<<endl;
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