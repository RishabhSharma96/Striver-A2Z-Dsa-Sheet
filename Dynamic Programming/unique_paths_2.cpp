class Solution
{
public:
    int solve(int lIndex, int uIndex, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
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
        if (uIndex > 0 && obstacleGrid[lIndex][uIndex - 1] == 0)
        {
            up = solve(lIndex, uIndex - 1, dp, obstacleGrid);
        }
        int left = 0;
        if (lIndex > 0 && obstacleGrid[lIndex - 1][uIndex] == 0)
        {
            left = solve(lIndex - 1, uIndex, dp, obstacleGrid);
        }

        return dp[lIndex][uIndex] = (left + up);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // return solve(m-1,n-1,dp, obstacleGrid) ;

        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }

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
                if (uIndex > 0 && obstacleGrid[lIndex][uIndex - 1] == 0)
                {
                    up = dp[lIndex][uIndex - 1];
                }
                int left = 0;
                if (lIndex > 0 && obstacleGrid[lIndex - 1][uIndex] == 0)
                {
                    left = dp[lIndex - 1][uIndex];
                }

                dp[lIndex][uIndex] = (left + up);
            }
        }
        return dp[m - 1][n - 1];
    }
};