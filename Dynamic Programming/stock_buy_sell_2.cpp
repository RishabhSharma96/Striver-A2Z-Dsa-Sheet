class Solution {
public:

    int solve(vector<int>& prices, int index, int hasBought, vector<vector<int>> & dp){
        
        if(index == prices.size()){
            return 0 ;
        }

        if(dp[index][hasBought] != -1){
            return dp[index][hasBought];
        }

        int profit = INT_MIN ;

        if(!hasBought){
            int buy = -prices[index] + solve(prices,index+1,1,dp); 
            int notbuy = 0 + solve(prices,index+1,0,dp); 
            profit = max(buy,notbuy);
        }
        else{
            int sell = prices[index] + solve(prices,index+1,0,dp); 
            int notsell = 0 + solve(prices,index+1,1,dp); 
            profit = max(sell,notsell);
        }

        return dp[index][hasBought] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1 , vector<int> (2,-1));
        // return solve(prices,0,0,dp);

        vector<vector<int>> dp(n+1 , vector<int> (2,0));

        for(int index=n-1; index>=0 ; index--){
            for(int hasBought=0; hasBought<2 ;hasBought++){
                int profit = INT_MIN ;

                if(!hasBought){
                    int buy = -prices[index] + dp[index+1][1]; 
                    int notbuy = 0 + dp[index+1][0]; 
                    profit = max(buy,notbuy);
                }
                else{
                    int sell = prices[index] + dp[index+1][0]; 
                    int notsell = 0 + dp[index+1][1]; 
                    profit = max(sell,notsell);
                }

                dp[index][hasBought] = profit;
            }
        }

        return (dp[0][0]);
    }
};