class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {

        if (n <= 1)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int one = solve(n - 1, dp);
        int two = 0;
        if (n >= 2)
        {
            two = solve(n - 2, dp);
        }

        return dp[n] = one + two;
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        // return solve(n,dp);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int one = dp[i - 1];
            int two = 0;
            if (n >= 2)
            {
                two = dp[i - 2];
            }

            dp[i] = one + two;
        }

        return dp[n];
    }
};