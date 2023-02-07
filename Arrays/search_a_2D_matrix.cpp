class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i=0 ; 
        int j = (matrix.size() * matrix[0].size()) - 1 ;

        while(i<=j){

            int mid = (i+j)/2 ;

            int ele = matrix[mid / matrix[0].size()][mid % matrix[0].size()] ;

            if(target == ele){
                return true ;
            }

            if(target > ele){
                i = mid+1 ;
            }
            
            else{
                j = mid-1 ;
            }

        }

        return false ;

    }
};