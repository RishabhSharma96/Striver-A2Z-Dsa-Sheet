class Solution
{
public:
    int findFloor(vector<int> &nums, long long n, long long target)
    {

        long long i = 0, j = nums.size() - 1;

        long long mid = i + (j - i) / 2;
        int ans = INT_MIN;
        while (i <= j)
        {

            mid = i + (j - i) / 2;
            if (nums[mid] <= target)
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

    int searchInsert(vector<int> &nums, int target)
    {
        if (target < nums[0])
            return 0;

        int index = findFloor(nums, nums.size(), target);
        return nums[index] == target ? index : index + 1;
    }
};