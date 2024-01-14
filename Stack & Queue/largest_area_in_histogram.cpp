class Solution {
public:

    void minimumToLeft(vector<int> & leftmin, vector<int> heights){

        stack<pair<int,int>> st; 
        st.push({-1,-1});

        for(int i=0 ; i<heights.size() ; i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop() ;
            }
            leftmin.push_back(st.top().second);
            st.push({heights[i],i});
        }
    }

    void minimumToRight(vector<int> & rightmin, vector<int> heights){

        stack<pair<int,int>> st; 
        st.push({-1, heights.size()});

        for(int i=heights.size()-1;  i>=0 ; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop() ;
            }
            rightmin.push_back(st.top().second);
            st.push({heights[i],i});
        }
        reverse(rightmin.begin(), rightmin.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size() ;

        vector<int> leftmin;
        minimumToLeft(leftmin,heights);
        vector<int> rightmin;
        minimumToRight(rightmin,heights);

        long long maxArea = 0;
        for(int i=0 ; i<n ; i++){
            long long leftArea = heights[i] * (i-leftmin[i]);
            long long rightArea = heights[i] * (rightmin[i]-i-1);
            maxArea = max(maxArea, leftArea + rightArea);
        }

        return maxArea ;

    }
};