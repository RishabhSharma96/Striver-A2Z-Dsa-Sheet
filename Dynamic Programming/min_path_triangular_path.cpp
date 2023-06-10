class Solution
{
public:
    int solve(vector<vector<int>> &triangle, int uIndex, int lIndex, vector<vector<int>> dp)
    {

        if (dp[uIndex][lIndex] != -1)
        {
            return dp[uIndex][lIndex];
        }

        if (uIndex == triangle.size() - 1)
        {
            return triangle[uIndex][lIndex];
        }

        int down = INT_MAX;
        down = triangle[uIndex][lIndex] + solve(triangle, uIndex + 1, lIndex, dp);
        int diagonal = INT_MAX;
        diagonal = triangle[uIndex][lIndex] + solve(triangle, uIndex + 1, lIndex + 1, dp);

        return dp[uIndex][lIndex] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        // vector<vector<int>> dp(m , vector<int> (m, -1)) ;
        // return solve(triangle,0,0,dp) ;

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            dp[m - 1][i] = triangle[m - 1][i];
        }

        for (int uIndex = m - 2; uIndex >= 0; uIndex--)
        {
            for (int lIndex = uIndex; lIndex >= 0; lIndex--)
            {
                int down = INT_MAX;
                down = triangle[uIndex][lIndex] + dp[uIndex + 1][lIndex];
                int diagonal = INT_MAX;
                diagonal = triangle[uIndex][lIndex] + dp[uIndex + 1][lIndex + 1];

                dp[uIndex][lIndex] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};