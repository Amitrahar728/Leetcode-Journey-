class Solution {
public:
    string decimaltobinary(int n){
        string s ="";
        while(n>0){
            int rem = n%2;
            s += '0'+rem;
            n=n/2;
        }
        return s;
    }
    bool hasAlternatingBits(int n) {
        string s = decimaltobinary(n);
        bool check = true;
        for(int i =0; i<s.size()-1; i++){
            if(s[i]==s[i+1]){
                check = false;
            }
        }
        return check;
    }
};