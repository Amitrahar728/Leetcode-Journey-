class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>> strictlyinc;
        int start =0;
        int profit =0;
        for(int i =1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[start];
                start = i;
            }
            else {
                start = i;
            }
        }
        return profit;
    }
};