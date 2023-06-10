// User function template for C++

class Solution
{
public:
    bool solve(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
    {

        if (dp[index][sum] != -1)
        {
            return dp[index][sum];
        }

        if (sum == 0)
        {
            return 1;
        }

        if (index == 0)
        {
            if (sum == arr[0])
            {
                return 1;
            }
            return 0;
        }

        bool nottake = solve(arr, sum, index - 1, dp);
        bool take = 0;
        if (sum >= arr[index])
        {
            take = solve(arr, sum - arr[index], index - 1, dp);
        }

        return dp[index][sum] = take || nottake;
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(sum+1, -1));
        // return solve(arr,sum,n-1,dp);

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        if (sum >= arr[0])
        {
            dp[0][arr[0]] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            for (int s = 1; s <= sum; s++)
            {
                bool nottake = dp[index - 1][s];
                bool take = 0;
                if (s >= arr[index])
                {
                    take = dp[index - 1][s - arr[index]];
                }

                dp[index][s] = take || nottake;
            }
        }

        return dp[n - 1][sum];
    }
};