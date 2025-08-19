class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long  cnt =0 ;
        long long sum =0;
        while(sum<neededApples){
            cnt++;
            long long mul = cnt*cnt;
            sum+=(12*mul);
        }
        return 8*cnt;

    }
};