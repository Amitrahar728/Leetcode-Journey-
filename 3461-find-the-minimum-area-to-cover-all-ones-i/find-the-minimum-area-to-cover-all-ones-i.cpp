class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // int max_row =-1;
        // int min_row = grid.size();
        // int max_col = -1;
        // int min_col = grid[0].size();

        // for(int i =0; i<grid.size(); i++){
        //     for(int j =0; j<grid[0].size(); j++){
        //         if(grid[i][j]==1){
        //             max_row =min(max_row,i);
        //             min_row = max(min_row, i);
        //             max_col = min(max_col,j);
        //             min_col = max(min_col,j);
        //         }
        //     }
        // }
        // // if(max_row ==0 ) return max_col;
        // // else if(max_col == 0) return max_row;
        // // max_row++;
        // // max_col++;


        // return (max_row-min_row+1)*(max_col-min_col+1);

        int m = grid.size();
        int n = grid[0].size();

        int t=n,b=-1;
        int l=m,r=-1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    l=min(l,i);
                    r=max(r,i);

                    t=min(t,j);
                    b=max(b,j);
                }
            }
        }

        return (r-l+1)*(b-t+1);
    }
};