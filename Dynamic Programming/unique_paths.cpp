class Solution
{
public:
    int solve(int lIndex, int uIndex, vector<vector<int>> &dp)
    {

        if (lIndex == 0 && uIndex == 0)
        {
            return 1;
        }

        if (dp[lIndex][uIndex] != -1)
        {
            return dp[lIndex][uIndex];
        }

        int up = 0;
        if (uIndex > 0)
        {
            up = solve(lIndex, uIndex - 1, dp);
        }
        int left = 0;
        if (lIndex > 0)
        {
            left = solve(lIndex - 1, uIndex, dp);
        }

        return dp[lIndex][uIndex] = (left + up);
    }

    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(m-1,n-1,dp) ;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int lIndex = 0; lIndex < m; lIndex++)
        {
            for (int uIndex = 0; uIndex < n; uIndex++)
            {

                if (lIndex == 0 && uIndex == 0)
                {
                    continue;
                }

                int up = 0;
                if (uIndex > 0)
                {
                    up = dp[lIndex][uIndex - 1];
                }
                int left = 0;
                if (lIndex > 0)
                {
                    left = dp[lIndex - 1][uIndex];
                }

                dp[lIndex][uIndex] = (left + up);
            }
        }
        return dp[m - 1][n - 1];
    }
};