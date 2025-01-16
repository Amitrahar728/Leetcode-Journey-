class Solution {
public:
    int arrangeCoins(int n) {
        long long low =0; long long high =n;
        int result =0;
        while(low<=high){
            long long mid = (low+high)/2;
            long long coin = (mid*(mid+1))/2;

            if(coin == n) return mid;
            else if(coin < n){
                result = mid ;
                low = mid + 1;
            }
            else high = mid -1;

        }
        
      return result;}
};