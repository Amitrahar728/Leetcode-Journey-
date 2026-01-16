class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        long long maxwidth =1;
        long long maxheight =1;
        long long x =2;
        long long start = 1;
        long i =0;
        while(i<hBars.size()){
            if(hBars[i] == x){
                maxheight =max(x-start+1 , maxheight);
                i++;
            }
            else{
                x = hBars[i]-1;
                start = x;
            }
            x++;
        }

        i=0;
        long long y =2;
        long long start2 =1;
        while(i<vBars.size()){
            if(vBars[i] == y){
                maxwidth =max(y-start2+1 , maxwidth);
                i++;
            }
            else{
                y=vBars[i]-1;
                start2 = y;
            }
            y++;
        }

        long long side2 = min(maxheight, maxwidth);
        return side2*side2;

    }
};