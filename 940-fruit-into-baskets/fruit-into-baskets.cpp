class Solution {
public:

   
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l =0;
        int r =0; 
        int maxlen =0;
        unordered_map<int, int> mp;
        int k =2;
            
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>k){
               
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;
                
            }
            if(mp.size()<=k) maxlen = max(maxlen,r-l+1);
            r++;
            }
   
        return maxlen;
        
    }
};