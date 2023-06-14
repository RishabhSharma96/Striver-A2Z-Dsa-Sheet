class Solution
{
public:
    int solve(int index, int W, int wt[], int val[], vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (W >= wt[0])
            {
                return (W / wt[0]) * val[0];
            }
            return 0;
        }

        if (dp[index][W] != -1)
        {
            return dp[index][W];
        }

        int nottake = solve(index - 1, W, wt, val, dp);
        int take = 0;
        if (wt[index] <= W)
        {
            take = val[index] + solve(index, W - wt[index], wt, val, dp);
        }

        return dp[index][W] = max(take, nottake);
    }

    int knapSack(int n, int W, int val[], int wt[])
    {
        // vector<vector<int> > dp (n  ,vector<int>(W+1, -1));
        // return solve(n-1,W,wt,val,dp);

        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        for (int weight = wt[0]; weight <= W; weight++)
        {
            dp[0][weight] = (weight / wt[0]) * val[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int weight = 0; weight <= W; weight++)
            {
                int nottake = dp[index - 1][weight];
                int take = INT_MIN;
                if (wt[index] <= weight)
                {
                    take = val[index] + dp[index][weight - wt[index]];
                }

                dp[index][weight] = max(take, nottake);
            }
        }

        return dp[n - 1][W];
    }
};