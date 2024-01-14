class Solution {
public:

    void minimumToLeft(vector<int> &leftmin, vector<int> heights) {
        stack<pair<int, int>> st;
        st.push({-1, -1});

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }
            leftmin.push_back(st.top().second);
            st.push({heights[i], i});
        }
    }

    void minimumToRight(vector<int> &rightmin, vector<int> heights) {
        stack<pair<int, int>> st;
        st.push({-1, heights.size()});

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }
            rightmin.push_back(st.top().second);
            st.push({heights[i], i});
        }
        reverse(rightmin.begin(), rightmin.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> leftmin;
        minimumToLeft(leftmin, heights);
        vector<int> rightmin;
        minimumToRight(rightmin, heights);

        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long currArea = heights[i] * ((i - leftmin[i]) + (rightmin[i] - i - 1));
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int numRows = matrix.size();
        int numCols = matrix[0].size();
        
        vector<int> varHeights(numCols, 0);
        int ans = 0;

        for (int i = 0; i < numRows; i++) {
            ans = max(ans, largestRectangleArea(varHeights));

            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] == '0') {
                    varHeights[j] = 0;
                } else {
                    varHeights[j] += matrix[i][j] - '0'; // Convert char to int
                }
            }
        }
        ans = max(ans, largestRectangleArea(varHeights));

        return ans;
    }
};
