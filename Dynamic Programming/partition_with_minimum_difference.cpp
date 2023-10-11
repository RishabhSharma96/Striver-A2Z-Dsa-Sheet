class Solution{

  public:
	int minDifference(int arr[], int n)  { 

        int sum=0 ;
        for(int i=0 ; i<n ;i++){
            sum += arr[i]; 
        }
        
        vector<vector<int>> dp(n , vector<int>(sum+1, 0));
        
        if(sum >= arr[0]){
            dp[0][sum] = 1 ;
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

        int ans = INT_MAX;
        for(int target=0; target<=sum ; target++){
            if(dp[n-1][target] == 1){
                int s1 = target ;
                int s2 = sum - target;
                ans = min(ans, abs(s2-s1));
            }
        }
        return ans;
	} 
};