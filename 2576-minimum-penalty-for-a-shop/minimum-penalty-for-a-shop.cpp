class Solution {
public:
    int bestClosingTime(string customers) {
        int cnty =0;
        int cntn =0;
        for(char x: customers){
            if(x=='Y'){
                cnty++;
            }
            else{
                cntn++;
            }
        }

        int penalty = cnty;
        int hour = 0;
        int mini = penalty ;
        for(int i =0; i<customers.length(); i++){
            if(customers[i] =='Y'){
                penalty--;
                
            }
            else if(customers[i]=='N'){
                penalty++;
            }
            if(penalty<mini){
                hour =i+1;
                mini = penalty;
            }
            

        }
        return hour;
    }
};