class Solution {
public:

    int solve(vector<int>& prices, int index, int hasBought, int transactions, vector<vector<vector<int>>> dp){
        
        if(index == prices.size() || transactions==0){
            return 0 ;
        }

        if(dp[index][hasBought][transactions] != -1){
            return dp[index][hasBought][transactions] ;
        }

        int profit = INT_MIN ;

        if(!hasBought){
            int buy = -prices[index] + solve(prices,index+1,1,transactions,dp); 
            int notbuy = 0 + solve(prices,index+1,0,transactions,dp); 
            profit = max(buy,notbuy);
        }
        else{
            int sell = prices[index] + solve(prices,index+1,0,transactions-1,dp); 
            int notsell = 0 + solve(prices,index+1,1,transactions,dp); 
            profit = max(sell,notsell);
        }

        return dp[index][hasBought][transactions] =  profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        // vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (k+1, -1)));
        // return solve(prices,0,0,k,dp);

        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));

        for(int index=n-1 ; index>=0 ; index--){
            for(int hasBought=0 ; hasBought<2; hasBought++){
                for(int transactions=1 ; transactions<=k ;  transactions++){
                    int profit = INT_MIN ;

                    if(!hasBought){
                        int buy = -prices[index] + dp[index+1][1][transactions]; 
                        int notbuy = 0 + dp[index+1][0][transactions]; 
                        profit = max(buy,notbuy);
                    }
                    else{
                        int sell = prices[index] + dp[index+1][0][transactions-1]; 
                        int notsell = 0 + dp[index+1][1][transactions]; 
                        profit = max(sell,notsell);
                    }

                    dp[index][hasBought][transactions] =  profit;
                }
            }
        }

        int ans = INT_MIN ;
        for(int i=1 ; i<=k; i++){
            ans = max(ans,dp[0][0][i]);
        }

        return ans;
    }
};
























