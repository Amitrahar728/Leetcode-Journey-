class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        // if(l)
        int l =r;
        if(l!=0)
        l = r-1;
        else r++;
        vector<int> ans;
        while(k>0 && l>=0 && r<arr.size()){
            if(abs(arr[l] - x) <abs(arr[r] -x)){
                ans.push_back(arr[l]);
                l--;
            }
            else if(abs(arr[l] - x) == abs(arr[r] -x)){
                    if(arr[l]<arr[r]){
                        ans.push_back(arr[l]);
                        l--;
                    }
                    else {
                    ans.push_back(arr[r]); r++;
                    }
                
            }
            else{
                ans.push_back(arr[r]);
                r++;
            }
            k--;
        }
        // if(k!=0 && l<0){
        //     while(k-- && r<arr.size()){
        //         ans.push_back(arr[r]);
        //         r++;
        //     }
        // } 
        if(k!=0){
            while(k>0 && r<arr.size()){
                ans.push_back(arr[r]);
                r++;
                k--;
            }
            while(k>0 && l>=0){
                ans.push_back(arr[l]);
                l--;
                k--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};