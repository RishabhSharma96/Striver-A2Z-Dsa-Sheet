class Solution {
    public:
    
    int solve(int row, int col1, int col2, vector<vector<int>>& grid, int n, int m,vector<vector<vector<int>>> & dp){
        
        if(col1<0 || col1>=m || col2<0 || col2>=m){
            return -1e8;
        }
        
        if(row == n-1){
            if(col1 == col2){
                return grid[row][col1];
            }
            else{
                return grid[row][col1] + grid[row][col2];
            }
        }
        
        if( dp[row][col1][col2]  != -1){
            return  dp[row][col1][col2] ;
        } 
        
        int maxChocolates = INT_MIN;
        for(int dcol1=-1; dcol1<=1; dcol1++){
            for(int dcol2=-1; dcol2<=1; dcol2++){
                if(col1 == col2){
                    maxChocolates = max(maxChocolates,grid[row][col1] + solve(row+1,col1+dcol1,col2+dcol2,grid,n,m,dp));
                }
                else{
                    maxChocolates = max(maxChocolates, grid[row][col1] + grid[row][col2] + solve(row+1,col1+dcol1,col2+dcol2,grid,n,m,dp));
                }
            }
        }
        return dp[row][col1][col2] = maxChocolates;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(m, vector<int>(m,-1)));
        return solve(0,0,m-1,grid,n,m,dp);
        
    }
};