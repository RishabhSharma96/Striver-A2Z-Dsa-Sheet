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
    void solve(TreeNode *root, string helper, vector<string> &ans)
    {

        if (!root)
            return;

        if (root->right == NULL && root->left == NULL)
        {
            helper += to_string(root->val);
            ans.push_back(helper);
            return;
        }

        helper += to_string(root->val) + "->";

        solve(root->left, helper, ans);
        solve(root->right, helper, ans);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (root == NULL)
        {
            return ans;
        }
        string helper;
        solve(root, helper, ans);
        return ans;
    }
};