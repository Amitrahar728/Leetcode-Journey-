class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> str;
        int n = s.size();
        if(n%k != 0){
            int rem = n%k;
            for(int i =0; i<k-rem; i++){
                s+=fill;
            }
        }
        int i =0;
        while(i<n){
            string a ="";
            int j =0;
            while(j<k){
                a+=s[i];
                j++;
                i++;
            }
            str.push_back(a);
        }
        return str;
    }
};