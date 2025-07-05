class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501,0);
        for(int i =0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        int cnt =0;
        for(int i =0; i<arr.size(); i++){
            
            if(arr[i] == freq[arr[i]]){
                 cnt = max(cnt,arr[i]);
            }
        }
        if(cnt ==0 ) return -1;
        else return cnt;
    }
};