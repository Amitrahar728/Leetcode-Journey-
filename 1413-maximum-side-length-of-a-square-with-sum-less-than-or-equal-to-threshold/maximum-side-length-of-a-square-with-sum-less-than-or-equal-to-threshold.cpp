class Solution {
public:
    bool valid(vector<vector<int>> pref , int k , int limit){
        int n = pref.size();
        int m = pref[0].size();

        for (int i = k-1; i<n; i++){
            for (int j = k - 1; j < m; j++){
                int x1 = i - k + 1;
                int y1 = j - k + 1;

                int sum = pref[i][j]
                        - (x1 > 0 ? pref[x1 - 1][j] : 0)
                        - (y1 > 0 ? pref[i][y1 - 1] : 0)
                        + (x1 > 0 && y1 > 0 ? pref[x1 - 1][y1 - 1] : 0);

                if (sum <= limit)
                    return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int i =0; i<n;i++){
            for(int j =0; j<m; j++){
                prefix[i][j] = mat[i][j];
            
                if(i>0){
                    prefix[i][j]+=prefix[i - 1][j];
                }
            
                if(j>0){
                    prefix[i][j]+=prefix[i][j-1];
                }
                if(i>0 && j>0){
                    prefix[i][j]-=prefix[i-1][j-1];
                }
            }
        }
        int low = 1;
        int high = min(n,m);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(valid(prefix , mid, threshold)){
                ans = mid;
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;


    }
};