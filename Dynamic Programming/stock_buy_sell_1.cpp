class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 ;
        int mini = prices[0] ;

        for(int i=0 ; i<prices.size() ; i++){
            int profit_loss = - mini + prices[i] ;
            mini = min(mini,prices[i]);
            maxProfit = max(maxProfit,profit_loss);
        }
        return maxProfit;
    }
};