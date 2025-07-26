class Solution {
public:
static bool cmp(pair<int,int> a, pair<int,int> b){
     return a.second > b.second; 
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> unique;
        int n = nums.size();
        int i =0;
        while(i<n){
            int ind = upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin();
            
            
            
            
            unique.push_back({nums[i], ind-i});
            i = ind;
        

        }
        vector<int> ans;
        sort(unique.begin(), unique.end(), cmp);
        for(int i =0; i<k; i++){
            
            ans.push_back(unique[i].first);
        }
        return ans;
    }

};