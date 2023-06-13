class Solution {
public:

    int solve(vector<int>& coins, int total, int index, vector<vector<int>> & dp){

        if(index == 0){
            if(total % coins[0] == 0){
                return dp[index][total] = total/coins[0];
            }
            return 1e8;
        }

        if(dp[index][total] != -1){
            return dp[index][total] ;
        }

        int nottake = solve(coins,total,index-1,dp);
        int take = INT_MAX ;
        if(coins[index] <= total){
            take = 1 + solve(coins,total-coins[index], index,dp) ;
        }

        return dp[index][total] = min(take,nottake) ;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp (n , vector<int> (amount+1 , -1));
        // int ans = solve(coins,amount,n-1,dp) ;
        // if(ans == 1e8){
        //     return -1 ;
        // }
        // return ans;

        vector<vector<int>> dp (n , vector<int> (amount+1 , 0));

        for(int i=0 ; i<=amount ; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
            else{
                dp[0][i] = 1e8;
            }
        }

        for(int index=1 ;index<n ;  index++){
            for(int total = 0 ; total<=amount ; total++){
                int nottake = dp[index-1][total];
                int take = INT_MAX ;
                if(coins[index] <= total){
                    take = 1 + dp[index][total-coins[index]];
                }
                dp[index][total] = min(take,nottake) ;
            }
        }

        int ans = dp[n-1][amount];
        if(ans == 1e8){
            return -1 ;
        }
        return ans;
    }
};