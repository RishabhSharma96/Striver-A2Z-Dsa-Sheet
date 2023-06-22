class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        int k=2;

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