class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(10001,INT_MAX);
        dp[0] =0;
        for(int i =0; i<dp.size(); i++){
            int j = 1;
            while(j*j<=i){
                dp[i] = min(dp[i] , dp[i-j*j]+1);
                j++;
            }
            
        }
        return dp[n];
        
    }
};