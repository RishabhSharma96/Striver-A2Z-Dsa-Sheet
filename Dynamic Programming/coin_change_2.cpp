class Solution
{
public:
    int solve(vector<int> &coins, int total, int index, vector<vector<int>> &dp)
    {

        if (index == 0)
        {
            if (total == 0)
                return 1;
            if (total % coins[0] == 0)
                return 1;
            return 0;
        }

        if (dp[index][total] != -1)
        {
            return dp[index][total];
        }

        int nottake = solve(coins, total, index - 1, dp);
        int take = 0;
        if (coins[index] <= total)
        {
            take = solve(coins, total - coins[index], index, dp);
        }

        return dp[index][total] = (take + nottake);
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // vector<vector<int>> dp (n , vector<int> (amount+1 , -1));
        // return solve(coins,amount,n-1,dp) ;

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int total = 0; total <= amount; total++)
        {
            if (total == 0)
                dp[0][total] = 1;
            else if (total % coins[0] == 0)
                dp[0][total] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            for (int total = 0; total <= amount; total++)
            {
                int nottake = dp[index - 1][total];
                int take = 0;
                if (coins[index] <= total)
                {
                    take = dp[index][total - coins[index]];
                }

                dp[index][total] = (take + nottake);
            }
        }
        return dp[n - 1][amount];
    }
};