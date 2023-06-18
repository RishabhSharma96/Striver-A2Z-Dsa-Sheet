/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.

    int solve(Node *root)
    {

        if (!root->left && !root->right)
        {
            return root->data;
        }

        int left = 0;
        if (root->left)
            left += solve(root->left);
        int right = 0;
        if (root->right)
            right += solve(root->right);

        if (left + right == root->data)
        {
            return root->data;
        }
        return -1e8;
    }

    int isSumProperty(Node *root)
    {
        return solve(root) != root->data ? 0 : 1;
    }
};