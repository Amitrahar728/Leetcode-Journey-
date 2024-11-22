class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
          int ret = 0;
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns

        // To store the frequency of patterns
        unordered_map<string, int> patternCount;

        for (int i = 0; i < m; i++) {
            string normalPattern, flippedPattern;

            // Create patterns for the current row
            for (int j = 0; j < n; j++) {
                normalPattern += to_string(matrix[i][j]);
                flippedPattern += to_string(1 - matrix[i][j]);
            }

            // Count both normal and flipped patterns
            patternCount[normalPattern]++;
            patternCount[flippedPattern]++;
        }
        for (const auto& entry : patternCount) {
            ret = max(ret, entry.second);
        }

        return ret;
    }
};