class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int  n = strs.size();
        int mini = INT_MAX;
        for(int i =0; i<n; i++){
            int x = strs[i].length();
            mini = min(mini, x);
        }
        int i =0;
        for(i =0; i<mini; i++){
            bool check = true;
            for(int j =0; j<strs.size()-1; j++){
                if(strs[j][i] != strs[j+1][i]){
                    check = false;
                }
            }
            if(check ==false){
                break;
            }
           
        }
        string ss = "";
        // i--;
        for(int k = 0; k<i; k++){
            ss+=strs[0][k];
        }
        return ss;
    }
};