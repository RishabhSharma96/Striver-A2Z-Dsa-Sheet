class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;

        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();

        int k = -1;

        while (i < n && j < m)
        {

            if ((nums1[i] == nums2[j]) && (k == -1))
            {
                k++;
                ans.push_back(nums1[i]);
                i++;
                j++;
            }

            else if ((nums1[i] == nums2[j]) && (nums1[i] != ans[k]))
            {
                k++;
                ans.push_back(nums1[i]);
                i++;
                j++;
            }

            else if (nums1[i] < nums2[j])
            {
                i++;
            }

            else if (nums2[j] < nums1[i])
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return ans;
    }
};