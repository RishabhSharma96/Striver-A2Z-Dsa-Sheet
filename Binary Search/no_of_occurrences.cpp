// User function template for C++

class Solution
{
public:
    int floor(int nums[], int n, int target)
    {

        long long i = 0, j = n - 1;

        long long mid = i + (j - i) / 2;
        int ans = -1;

        while (i <= j)
        {

            mid = i + (j - i) / 2;
            if (nums[mid] <= target && nums[mid] == target)
            {
                ans = mid;
            }

            if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return ans;
    }

    int ciel(int nums[], int n, int target)
    {

        long long i = 0, j = n - 1;

        long long mid = i + (j - i) / 2;
        int ans = -1;

        while (i <= j)
        {

            mid = i + (j - i) / 2;
            if (nums[mid] >= target && nums[mid] == target)
            {
                ans = mid;
            }

            if (nums[mid] >= target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(int nums[], int n, int target)
    {
        sort(nums, nums + n);
        pair<int, int> cf;
        cf.first = floor(nums, n, target);
        cf.second = ciel(nums, n, target);
        return cf;
    }

    int searchRange(int nums[], int n, int target)
    {
        vector<int> ans;
        pair<int, int> p = getFloorAndCeil(nums, n, target);
        ans.push_back(p.second);
        ans.push_back(p.first);
        if (ans[0] == -1 || ans[1] == -1)
            return 0;
        return abs(ans[0] - ans[1]) + 1;
    }

    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0.  */
    int count(int nums[], int n, int x)
    {
        return searchRange(nums, n, x);
    }
};