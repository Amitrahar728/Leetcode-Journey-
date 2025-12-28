class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int x  = 0;
        int y ;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]<0){
                    int rem = m-j;
                    int reminn = n-i;
                    x+=rem*reminn;
                    m = j;
                    break;
                }
            }
        }
        return x;
    }
};