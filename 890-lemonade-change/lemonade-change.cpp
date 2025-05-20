class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mpp;
        if(bills[0] != 5) return false;
        for(int i =0; i<bills.size(); i++){
            if(bills[i]==5){
                mpp[5]++;

            }
            else if(bills[i]==10){
                mpp[10]++;
                if(mpp[5]> 0){
                mpp[5]--;} 
                else return false;
            }
            else{
                mpp[20]++;
                if(mpp[10]>0 && mpp[5]>0){
                    mpp[5]--;
                    mpp[10]--;
                }
                else if(mpp[5]>2){
                    mpp[5]--;
                    mpp[5]--;
                    mpp[5]--;
                }
                else{
                    return false;
                }

            }

        }
        return true;
    }
};