class Solution {
public:
    string addBinary(string a, string b) {
        string s ="";
        int diff = a.size() - b.size();
        int absdiff = a.size()-b.size();
        if(absdiff<0){
            absdiff = absdiff - (2*absdiff);
        }
        for(int i =0; i<absdiff; i++){
            s+='0';
        }
        if(diff>0){
            s+=b;
            b=s;
        }
        else if(diff<0){
            s+=a;
            a=s;
        }
        int carry = 0;
        string one = "";
        cout<<a<<" "<<b<<endl;
        for(int i =a.size()-1; i>=0; i--){
            if(a[i]== '1' && b[i] == '1' && carry == 1){
                carry =1;
                one+='1';
            }
            else if((a[i] == '1' && b[i] == '1' && carry == 0 )||(a[i] == '0' &&b[i]=='1' &&carry == 1)|| (a[i] == '1' &&b[i]=='0' &&carry == 1)){
                carry = 1;
                one+='0';
            }
            else if(a[i] == '0' && b[i] == '0' && carry == 0){
                carry = 0;
                one+='0';
            }
            else {
                carry = 0;
                one+='1';
            }
        }
        if(carry == 1){
            one+='1';
        }
        cout<<one<<endl;

        string two = "";
        for(int i = one.size()-1; i>=0; i--){
            two+=one[i];
        }
        return two;
        
    }
};