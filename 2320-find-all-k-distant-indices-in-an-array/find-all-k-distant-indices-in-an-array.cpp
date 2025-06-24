class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyoccur;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == key){
                keyoccur.push_back(i);
            }
        }
        vector<int> ans;
        int  n = nums.size();
        vector<int> vis(n,0) ;
        for(int i =0; i<nums.size(); i++){
            for(int j =0; j<keyoccur.size(); j++){
                if(abs(i-keyoccur[j])<=k && vis[i] == 0){
                    ans.push_back(i);
                    vis[i]=1;
                }
            }
        }
            sort(ans.begin(), ans.end());
        return ans;
    }
};