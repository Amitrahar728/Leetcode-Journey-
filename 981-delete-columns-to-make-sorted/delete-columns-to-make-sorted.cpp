class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int size = strs[0].length();
        int cnt =0;
        for(int i =0; i<size; i++){
            for(int j =0; j<strs.size()-1; j++){
                if(static_cast<int>(strs[j][i]) > static_cast<int>(strs[j+1][i])){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;

    }
};