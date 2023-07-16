class Solution{

	public:
	
	const int mod = 1000000007 ;
	
	int solve(int arr[], int index, int target, vector<vector<int>> & dp){
	       
	       if(dp[index][target] != -1){
	           return dp[index][target] ;
	       }
	       
	       if(index == 0){
    	        if(target == 0 && arr[0] == 0){
                    return 2;
                }
                if(target==0 || target == arr[0]){
                    return 1 ;
                }
                else{
                    return 0 ;
                }
	       }
	       
	       int notTake = solve(arr,index-1,target,dp);
	       int take = 0 ;
	       if(arr[index] <= target){
	           take += solve(arr,index-1,target-arr[index],dp) ;
	       }
	       
	       return dp[index][target] = (take+notTake)%mod ;
	}

	
	int perfectSum(int arr[], int n, int sum)
	{
	   // vector<vector<int>> dp (n , vector<int>(sum+1 , -1));
    //     return solve(arr,n-1,sum,dp);
    
	    vector<vector<int>> dp (n , vector<int>(sum+1 , 0));
    
        if(arr[0] == 0) dp[0][0] = 2; 
        else dp[0][0] = 1;  
        
        if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]] = 1;
        
        for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=sum; target++){
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
            }
        }
        return dp[n-1][sum];
	}
};