class Solution {
public:
    int func(int n , int x, vector<int> &dp){
        if(x==n){
            
            return 1 ;
        } 
        if (x > n) return 0 ;
        if(dp[x]!=-1){
            return dp[x];
        }
        int sum =func(n,x+1,dp);
        sum+=func(n,x+2,dp);

        dp[x] = sum;
        return dp[x];
    }
    int climbStairs(int n) {
            int x =0;
            // int cnt =0;
            vector<int> dp(n+1,-1);
            // func(n, x, cnt);
            return   func(n, x, dp);
    }
};