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
    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = 0;
        if (root->left)
            left = 1 + solve(root->left);

        int right = 0;
        if (root->right)
            right = 1 + solve(root->right);

        return left + right;
    }

    int countNodes(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        return solve(root) + 1;
    }
};