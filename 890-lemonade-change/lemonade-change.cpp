class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         int five =0;
         int ten =0;
        if(bills[0] != 5) return false;
        for(int i =0; i<bills.size(); i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                ten++;
                if(five>0){
                five--;} 
                else return false;
            }
            else{
                
                if(ten>0 && five>0){
                    five--;
                    ten--;
                }
                else if(five>2){
                    five--;
                    five--;
                    five--;
                }
                else{
                    return false;
                }

            }

        }
        return true;
    }
};