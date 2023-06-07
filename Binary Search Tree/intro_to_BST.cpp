class Solution
{
public:
    bool isBSTTraversal(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};