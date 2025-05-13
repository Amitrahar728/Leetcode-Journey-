class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));
        int maxarea = 0;

        // Build prefix sum histogram matrix
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    psum[i][j] = (i > 0 ? psum[i - 1][j] : 0) + 1;
                } else {
                    psum[i][j] = 0;
                }
            }
        }

        // For each row, treat it as histogram
        for (int i = 0; i < n; i++) {
            maxarea = max(maxarea, largestRectangleArea(psum[i]));
        }

        return maxarea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> leftsmall(n), rightsmall(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftsmall[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightsmall[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }

        return maxA;
    }
};
