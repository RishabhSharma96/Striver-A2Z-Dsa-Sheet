class Solution
{
public:
    int solve(int lIndex, int uIndex, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {

        if (lIndex == 0 && uIndex == 0)
        {
            return grid[0][0];
        }

        if (dp[lIndex][uIndex] != -1)
        {
            return dp[lIndex][uIndex];
        }

        int up = INT_MAX;
        if (uIndex > 0)
        {
            up = grid[lIndex][uIndex] + solve(lIndex, uIndex - 1, dp, grid);
        }
        int left = INT_MAX;
        if (lIndex > 0)
        {
            left = grid[lIndex][uIndex] + solve(lIndex - 1, uIndex, dp, grid);
        }

        return dp[lIndex][uIndex] = min(left, up);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(m-1,n-1,dp, grid) ;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int lIndex = 0; lIndex < m; lIndex++)
        {
            for (int uIndex = 0; uIndex < n; uIndex++)
            {

                if (lIndex == 0 && uIndex == 0)
                {
                    continue;
                }

                int up = INT_MAX;
                if (uIndex > 0)
                {
                    up = grid[lIndex][uIndex] + dp[lIndex][uIndex - 1];
                }
                int left = INT_MAX;
                if (lIndex > 0)
                {
                    left = grid[lIndex][uIndex] + dp[lIndex - 1][uIndex];
                }

                dp[lIndex][uIndex] = min(left, up);
            }
        }
        return dp[m - 1][n - 1];
    }
};