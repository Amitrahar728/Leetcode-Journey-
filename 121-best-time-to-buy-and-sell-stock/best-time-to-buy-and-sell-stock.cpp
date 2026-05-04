class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;

        int minpoint = prices[0];
        if(prices.size() == 1) return 0;
        // int maxpoint = prices[0];
        for(int i =1; i<prices.size(); i++){
           if(minpoint < prices[i]){
                maxprofit = max(prices[i]- minpoint , maxprofit);
           }
           minpoint = min(minpoint, prices[i]);
        }
        return maxprofit;
    }
};