class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; 
        unordered_set<int> uniqueColors;   
        vector<int> ans;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            if (ballColor.count(ball)) {
                int oldColor = ballColor[ball];
                if (--colorCount[oldColor] == 0) {
                    uniqueColors.erase(oldColor);
                }
            }

            ballColor[ball] = color;
            uniqueColors.insert(color);
            colorCount[color]++; 

            ans.push_back(uniqueColors.size());
        }

        return ans;
    }
    private:
    unordered_map<int, int> colorCount;
};