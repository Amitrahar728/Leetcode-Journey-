class Solution {
public:
    void dfs(int sr , int sc , vector<vector<int>> &ans , vector<vector<int>> &image ,int newcolor , vector<int> drow, vector<int> dcol , int ini ){
        // int ini = ans[]
        ans[sr][sc] = newcolor;
        int n = ans.size();
        int m = ans[0].size();
        for(int i =0; i<4; i++){
            int nrow = sr+drow[i];
            int ncol = sc+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]== ini && ans[nrow][ncol]!= newcolor){
                dfs(nrow, ncol , ans, image ,newcolor , drow , dcol ,ini);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> drow = {-1, 0, 1 , 0};
        vector<int> dcol = { 0,1,0,-1};
        dfs(sr,sc,ans,image,color,drow, dcol, ini);
        return ans;
    }
};