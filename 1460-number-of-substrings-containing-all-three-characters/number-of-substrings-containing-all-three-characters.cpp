class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen ={ -1,-1,-1};
        int cnt =0;
        for(int i =0; i<s.size(); i++){
            lastseen[s[i]-'a'] =i;
            int mini = min(lastseen[0],lastseen[1]);
            cnt = cnt +(1+min(mini,lastseen[2]));
        }
        return cnt;
    }
};