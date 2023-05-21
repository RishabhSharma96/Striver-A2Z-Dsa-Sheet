/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<pair<TreeNode *, pair<int, int>>> s; // node left right
        vector<int> ans;
        if (!root)
        {
            return ans;
        }

        s.push({root, {0, 0}});

        while (!s.empty())
        {
            if (s.top().first->left && s.top().second.first == 0)
            {
                s.top().second.first = 1;
                s.push({s.top().first->left, {0, 0}});
            }
            else
            {
                if (s.top().first->right && s.top().second.second == 0)
                {
                    s.top().second.second = 1;
                    s.push({s.top().first->right, {0, 0}});
                }
                else
                {
                    auto node = s.top();
                    ans.push_back(node.first->val);
                    s.pop();
                }
            }
        }
        return ans;
    }
};