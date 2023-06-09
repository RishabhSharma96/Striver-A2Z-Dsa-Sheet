class Solution
{
public:
    int solve(vector<int> &height, int index, vector<int> &dp)
    {

        if (index == 0)
            return 0;

        if (dp[index] != -1)
        {
            return dp[index];
        }

        int one = abs(height[index] - height[index - 1]) + solve(height, index - 1, dp);
        int two = INT_MAX;
        if (index >= 2)
        {
            two = abs(height[index] - height[index - 2]) + solve(height, index - 2, dp);
        }
        return dp[index] = min(one, two);
    }

    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, 0);
        // return abs(solve(height,n-1,dp));

        dp[0] = 0;

        for (int index = 1; index < n; index++)
        {
            int one = abs(height[index] - height[index - 1]) + dp[index - 1];
            int two = INT_MAX;
            if (index >= 2)
            {
                two = abs(height[index] - height[index - 2]) + dp[index - 2];
            }
            dp[index] = min(one, two);
        }
        return dp[n - 1];
    }
};