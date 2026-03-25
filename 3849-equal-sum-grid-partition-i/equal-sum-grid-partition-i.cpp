class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        int c;
        if(r!=0){
        c = grid[0].size();}
        else {
             c = 0;
        }

        long long sum =0; 
        for(int i =0; i<r; i++){
            for(int j =0; j<c; j++){
                sum+=grid[i][j];
            }
        }

        
        long long  sum1=0;
        long long sum2=0;
        for(int i =0; i<r-1; i++){
            for(int j =0; j<c; j++){
                sum1+=grid[i][j];
            }
            if(sum1*2 == sum) return true;
        }

        vector<long long > col(c,0);
        for(int i =0; i<c; i++){
            for(int j =0; j<r; j++){
                col[i]+=grid[j][i];
            }
        }


        for(int j =0 ;j<c-1; j++){
            sum2+=col[j];
            if(sum2*2 == sum) return true;
        }

        return false;
    }
};