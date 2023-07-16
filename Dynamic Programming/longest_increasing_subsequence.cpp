// MEMOIZATION
class Solution {
public:

    int solve(vector<int> & nums, int index, int prev_index, vector<vector<int>> & dp){
        if(index == nums.size()){
            return 0 ;
        }

        int nottake = solve(nums,index+1,prev_index,dp);
        int take = INT_MIN;
        if(prev_index==-1 || nums[index] > nums[prev_index]){
            take = 1 + solve(nums,index+1,index,dp);
        }
        return dp[index][prev_index+1] = max(take,nottake);
        
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1,-1)) ;
        return solve(nums,0,-1,dp);
    }
};


// TABULATION - O(N^2)
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp (n+1, vector<int> (n+1,0)) ;

        for(int index = n-1; index>=0; index --){
            for (int prev_index = index-1; prev_index >=-1; prev_index --){
                
                int notTake = 0 + dp[index+1][prev_index +1];
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index]){
                    take = 1 + dp[index+1][index+1];
                }
                dp[index][prev_index+1] = max(notTake,take); 
            }
        }
        return dp[0][0] ;
    }
};


// TABULATION (NlogN)

