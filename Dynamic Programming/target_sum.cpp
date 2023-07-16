class Solution {
public:

    int solve(vector<int> & arr, int index, int target, vector<vector<int>> & dp){
	       
			if (dp[index][target] != -1){
				return dp[index][target];
			}

			if (index == 0){
				if (target == 0 && arr[0] == 0){
						return 2;
				}
				if (target == 0 || target == arr[0]){
						return 1;
				}
				else{
						return 0;
				}
			}

			int notTake = solve(arr, index - 1, target, dp);
			int take = 0;
			if (arr[index] <= target){
				take += solve(arr, index - 1, target - arr[index], dp);
			}

			return dp[index][target] = (take + notTake);
	}

    int findTargetSumWays(vector<int>& nums, int target) {
			int n = nums.size() ;

			int sum = 0; 
			for(auto it : nums){
				sum += it;
			}

			if ((sum + target) % 2 != 0 || target > sum || (sum + target) /2 < 0) return 0;
			sum = (target+sum)/2 ;

			// vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
			// return solve(nums, n - 1, sum , dp);

			vector<vector<int>> dp (n , vector<int>(sum+1 , 0));
    
        if(nums[0] == 0) dp[0][0] = 2; 
        else dp[0][0] = 1;  
        
        if(nums[0]!=0 && nums[0]<=sum) dp[0][nums[0]] = 1;
        
        for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=sum; target++){
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(nums[ind]<=target)
                    taken = dp[ind-1][target-nums[ind]];
        
            dp[ind][target]= (notTaken + taken);
            }
        }
        return dp[n-1][sum];
    }
};