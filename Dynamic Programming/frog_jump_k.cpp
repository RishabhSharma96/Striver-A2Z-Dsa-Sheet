class Solution
{
public:
    int solve(vector<int> &height, int index, int k, vector<int> &dp)
    {
        if (index == 0)
            return 0;

        if (dp[index] != -1)
        {
            return dp[index];
        }

        int ans = 1e8;
        for (int i = 1; i <= k; i++)
        {
            if (index >= i)
                ans = min(ans, (abs(height[index] - height[index - i]) + solve(height, index - i, k, dp)));
        }
        return dp[index] = ans;
    }

    int minimizeCost(vector<int> &height, int n, int k)
    {
        // vector<int> dp(n, -1);
        // return solve(height,n-1,k,dp);
        vector<int> dp(n, 0);

        dp[0] = 0;

        for (int index = 1; index < n; index++)
        {
            int ans = 1e8;
            for (int i = 1; i <= k; i++)
            {
                if (index >= i)
                    ans = min(ans, (abs(height[index] - height[index - i]) + dp[index - i]));
            }
            dp[index] = ans;
        }
        return dp[n - 1];
    }
};