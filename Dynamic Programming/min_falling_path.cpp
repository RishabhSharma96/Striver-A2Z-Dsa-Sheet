class Solution {
public:

    int solve(vector<vector<int>>& matrix, int row,int col, vector<vector<int>> & dp){

        if(row == matrix.size()-1){
            return matrix[row][col];
        }

        if(dp[row][col] != -1){
            return dp[row][col] ;
        }


        int left = 1e8 ;
        if(col-1>=0){
            left = matrix[row][col] + solve(matrix,row+1,col-1,dp);
        } 
        int down = matrix[row][col] + solve(matrix,row+1,col,dp);
        int right = 1e8;
        if(col+1< matrix.size()) {
            right = matrix[row][col] + solve(matrix,row+1,col+1,dp);
        }

        return dp[row][col] = min(left,min(down,right));

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int ans = 1e8;
        // int n = matrix.size() ;

        // vector<vector<int>> dp(n, vector<int> (n,-1));

        // for(int i=0 ; i<n ; i++){
        //     ans = min(ans,solve(matrix,0,i,dp));
        // }

        // return ans;


        int n = matrix.size() ;

        vector<vector<int>> dp(n, vector<int> (n,0));

        for(int i=0 ; i<n ; i++){
            dp[n-1][i] = matrix[n-1][i] ;
        }

        for(int row=n-2 ; row>=0 ; row--){
            for(int col=0 ; col < n ; col++){
                int left = 1e8 ;
                if(col-1>=0){
                    left = matrix[row][col] + dp[row+1][col-1];
                } 
                int down = matrix[row][col] + dp[row+1][col];
                int right = 1e8;
                if(col+1< matrix.size()) {
                    right = matrix[row][col] + dp[row+1][col+1];
                }

                dp[row][col] = min(left,min(down,right));
            }
        }

        int ans = INT_MAX ;

        for(int i=0 ; i<n ; i++){
            ans = min(ans,dp[0][i]);
        }

        return ans;

    }
};


























