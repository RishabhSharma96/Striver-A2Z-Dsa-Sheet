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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode *temp = root;

        while (temp != NULL)
        {
            if (val > temp->val)
            {
                if (temp->right == NULL)
                {
                    TreeNode *newNode = new TreeNode(val);
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->left == NULL)
                {
                    TreeNode *newNode = new TreeNode(val);
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
        return root;
    }
};