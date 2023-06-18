class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int i = 0, j = nums.size() - 1;

        int mid = i + (j - i) / 2;
        while (i <= j)
        {

            mid = i + (j - i) / 2;
            if (nums[mid] == target)
            {
                return mid;
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
        return -1;
    }
};