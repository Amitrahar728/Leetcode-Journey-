class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m =  grid.size(); int n = grid[0].size() , maxi =0;
        for(int i =2; i<m ; i++){
            for(int j =2 ; j<n; j++){
                int sum  = grid[i-2][j-2]+ grid[i - 2][j - 1] + grid[i - 2][j]
                + grid[i - 1][j - 1]+grid[i][j - 2]+ grid[i][j - 1]+ grid[i][j];
                maxi = max(maxi , sum);
            }
        }
        return maxi;
    }
};