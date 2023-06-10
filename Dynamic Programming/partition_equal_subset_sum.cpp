class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size() ;

        int sum=0 ;
        for(int i=0 ; i<n ;i++){
            sum += arr[i]; 
        }

        if(sum % 2 == 1) return false ;

        sum = sum/2 ;
        
        vector<vector<int>> dp(n , vector<int>(sum+1, 0));
        
        if(sum >= arr[0]){
            dp[0][arr[0]] = 1 ;
        }
        
        for(int i=0 ; i<n ;i++){
            dp[i][0] = 1 ;
        }
        
        for(int index=1; index<n ; index++){
            for(int s=1 ; s<=sum ; s++){
                bool nottake = dp[index-1][s];
                bool take = 0 ;
                if(s >= arr[index]){
                    take = dp[index-1][s - arr[index]];
                }
                
                dp[index][s] = take || nottake ;
            }
        }
        
        return dp[n-1][sum] ;
     
    }
};