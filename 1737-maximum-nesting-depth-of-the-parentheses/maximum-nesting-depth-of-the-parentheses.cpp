class Solution {
public:
    int maxDepth(string s) {
        int st =0;
        int j = s.length();
        int m = INT_MIN;
        int cnt = 0;
        for(int i =0; i<j; i++){
            if(s[i]=='('){
                cnt++;
            }
            
            else if(s[i] ==')') {cnt--;}
            if(cnt>m){
                m=cnt;
            }

        }
        return m;
    }
};