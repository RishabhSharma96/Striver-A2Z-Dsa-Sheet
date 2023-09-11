class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size() ;
        int rowTraverser = 0, colTraverser = m-1;

        while(rowTraverser<n && colTraverser>=0){

            if(matrix[rowTraverser][colTraverser] == target){
                return true;
            }
            else if(matrix[rowTraverser][colTraverser] > target){
                colTraverser--;
            }
            else{
                rowTraverser++;
            }
        }
        return false;
    }
};