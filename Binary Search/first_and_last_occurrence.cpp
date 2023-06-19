class Solution
{
public:
    int floor(vector<int> &nums, int n, int target)
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

    int ciel(vector<int> &nums, int n, int target)
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

    pair<int, int> getFloorAndCeil(vector<int> &nums, int n, int target)
    {
        sort(nums.begin(), nums.end());
        pair<int, int> cf;
        cf.first = floor(nums, n, target);
        cf.second = ciel(nums, n, target);
        return cf;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        pair<int, int> p = getFloorAndCeil(nums, nums.size(), target);
        ans.push_back(p.second);
        ans.push_back(p.first);
        return ans;
    }
};