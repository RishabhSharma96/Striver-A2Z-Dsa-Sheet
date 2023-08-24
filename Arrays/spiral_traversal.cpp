class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int top=0, left=0, right=m-1, bottom=n-1;
        vector<int> ans;

        while(left<=right && top<=bottom){

            // printing top
            for(int i=left ; i<=right ; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // printing right
            for(int i=top ; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // printing bottom
            if(top <= bottom){   
                for(int i=right ; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // printing left
            if(left <= right){
                for(int i=bottom ; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }   
                left++;
            }
        }

        return ans;
    }
};