// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent

    int solve(int *arr, int index, vector<int> &dp)
    {

        if (dp[index] != -1)
        {
            return dp[index];
        }

        if (index == 0)
        {
            return arr[0];
        }

        int nottake = 0 + solve(arr, index - 1, dp);
        int take = arr[index];
        if (index > 1)
        {
            take += solve(arr, index - 2, dp);
        }

        return dp[index] = max(take, nottake);
    }

    int findMaxSum(int *arr, int n)
    {
        // vector<int> dp (n,-1);
        // return solve(arr,n-1,dp) ;

        vector<int> dp(n, 0);

        dp[0] = arr[0];

        for (int index = 1; index < n; index++)
        {
            int nottake = 0 + dp[index - 1];
            int take = arr[index];
            if (index > 1)
            {
                take += dp[index - 2];
            }

            dp[index] = max(take, nottake);
        }
        return dp[n - 1];
    }
};