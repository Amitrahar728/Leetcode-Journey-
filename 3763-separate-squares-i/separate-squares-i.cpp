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
        // Okaay so here we are seeing that all the square are upward facing so the line must line somewhere
        // in between the min y(i) and maximum y(i)+l(i)
        //  agar high y(i)+l(i)
        //  So we are going to apply Binary Search here because here we can see that until the areas are equal 
        //  we will go and check area below line and above line at every point the side it is high we will 
        // move are high and low in the opposite direction .
        //  how we will find area :
        // the y point is fixed for line which we will take as mid but 
        //  we will iterate through squares for every square the area will be divided by us .
        //  And about precision we are given about 10e-5 , So we are given with the precision 
        //  whenever precision is given to us we try to calculate search space before hand and iterate with 
        //  limited loop , iteration => log((high-low) * 10^k)
        //  but normally it is log(high-low)
        //  here high as of max can be 2*10^9 and low can be minimum of 0 so log(2*10^9 * 10^6) -> log(2*10^15)
        // for every 10^3 10 operations then total aroudn 50 take 55 on safer end .

        double low = 2e9;
        double high = 0;

        
        for(auto& x : squares) {
            low = min(low, (double)x[1]);
            if((double)x[1] + x[2] > high) high = (double)x[1] + x[2];
        }
        // double ans ;


        for(int  i =0; i<55; i++)
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