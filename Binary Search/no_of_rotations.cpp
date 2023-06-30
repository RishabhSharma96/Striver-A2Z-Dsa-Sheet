// User function template for C++
class Solution
{
public:
    int findKRotation(int nums[], int n)
    {
        int ans = INT_MAX;
        int rotated = 0;
        int i = 0, j = n - 1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            int prevAns = ans;

            if (nums[i] <= nums[mid])
            {
                ans = min(ans, nums[i]);
                if (ans != prevAns)
                {
                    rotated = i;
                }
                i = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                if (ans != prevAns)
                {
                    rotated = mid;
                }
                j = mid - 1;
            }
        }

        return rotated;
    }
};