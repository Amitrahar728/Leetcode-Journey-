class Solution {
public:
    int decimall(string s){
        int ans =0;
        for(int i =0; i<s.size(); i++){
            if(s[i] == '1'){
                ans+=(1<<i);
            }
        }
        return ans;
    }
    int longestSubsequence(string s, int k) {
        int ans =0;
        int n = s.size();
        for(int i =0; i<n; i++){
            if(s[i] =='0') ans++;
        }
        string bin = "";
        for(int i =n-1;i>=0; i--){
            bin+=s[i];
            if(s[i] =='1'){
                if(bin.size()>=32){
                    break;
                }
                int dec = decimall(bin);
                if(dec<=k){
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};