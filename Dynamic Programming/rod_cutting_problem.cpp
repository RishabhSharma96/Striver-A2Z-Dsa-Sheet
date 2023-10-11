class Solution{
    public:
    
    int solve(int index , int length, int price[] , int n, vector<vector<int>> & dp){
        if(index == 0){
            return length*price[0] ;
        }
        
        if(dp[index][length] != -1){
            return dp[index][length] ;
        }
        
        int notcut = 0 + solve(index-1,length,price,n,dp);
        int cut = INT_MIN ;
        int currRopeLength = index+1 ;
        if(currRopeLength <= length){
            cut = price[index] + solve(index, length-currRopeLength, price,n,dp);
        }
        return dp[index][length] = max(cut,notcut);
    }

    int cutRod(int price[], int n) {
        // vector<vector<int>> dp(n , vector<int> (n+1, -1));
        // return solve(n-1,n,price,n,dp) ;
        
        vector<vector<int>> dp(n , vector<int> (n+1, 0));
        
        for(int length=0 ; length<=n; length++){
            dp[0][length] = length*price[0] ;
        }
        
        for(int index=1; index<n; index++){
            for(int length=0 ; length<=n; length++){
                int notcut = 0 + dp[index-1][length];
                int cut = INT_MIN ;
                int currRopeLength = index+1 ;
                if(currRopeLength <= length){
                    cut = price[index] + dp[index][length-currRopeLength];
                }
                dp[index][length] = max(cut,notcut);
            }
        }
        return dp[n-1][n] ;
    }
};