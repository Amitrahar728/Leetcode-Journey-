class Solution {
public:

    int check(double mid , vector<vector<int>> & squares){
        double area1 =0;
        double area2 = 0;
        for(auto& x : squares){
            double total =(double)x[2] * x[2];
            if(x[1] >= mid){
                area2+=total;
            }
            else if(x[1]+x[2]>mid){
                double area = x[2]*(mid-x[1]);
                area1 +=area;
                area2 += total-area;

            }
            else{
                area1+=total;
            }
        }
        
        if(area1>= area2){
            return 1;
        }
        else {
            return -1;
        }
    }
    double separateSquares(vector<vector<int>>& squares) {
        

        double low = 2e9;
        double high = 0;

        
        for(auto& x : squares) {
            low = min(low, (double)x[1]);
            if((double)x[1] + x[2] > high) high = (double)x[1] + x[2];
        }
        // double ans ;


        for(int  i =0; i<50; i++)
        {
            double mid = low + (high - low) / 2.0;
            if(check(mid, squares) == 1){
                high = mid;
            }
            else if(check(mid , squares) == -1){
                low = mid;
            }
            
        }
        return low;

    }
};