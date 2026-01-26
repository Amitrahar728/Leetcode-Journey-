class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i =0; i<arr.size()-1; i++)
        {
            int diff = arr[i+1]-arr[i];
            mini = min(mini, diff);
        }
        vector<vector<int>> v;
        for(int i =0; i<arr.size()-1; i++){
            int diff = arr[i+1]-arr[i];
            if(diff == mini){
                vector<int> n;
                n.push_back(arr[i]);
                n.push_back(arr[i+1]);
                v.push_back(n);
            }
        }
        return v;
    }
};