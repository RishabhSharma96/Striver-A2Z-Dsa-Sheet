class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> nums, long long n, long long target)
    {

        long long i = 0, j = nums.size() - 1;

        long long mid = i + (j - i) / 2;
        int ans = -1;
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
};