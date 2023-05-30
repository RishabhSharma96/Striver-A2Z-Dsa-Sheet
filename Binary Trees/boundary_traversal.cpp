/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    void getLeft(Node *root, vector<int> &ans)
    {

        while (root->left || root->right)
        {

            if (!root->left && !root->right)
                break;

            if (root->left)
            {
                ans.push_back(root->data);
                root = root->left;
            }
            else if (root->right)
            {
                ans.push_back(root->data);
                root = root->right;
            }
        }
    }

    void getChild(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        getChild(root->left, ans);
        if (!root->left && !root->right)
        {
            ans.push_back(root->data);
        }
        getChild(root->right, ans);
    }

    void getRight(Node *root, vector<int> &ans)
    {

        stack<Node *> s;
        while (1)
        {
            if (!root->left && !root->right)
                break;

            if (root->right)
            {
                s.push(root);
                root = root->right;
            }
            else if (root->left)
            {
                s.push(root);
                root = root->left;
            }
        }

        while (!s.empty())
        {
            auto node = s.top();
            ans.push_back(node->data);
            s.pop();
        }
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (!root)
        {
            return ans;
        }

        ans.push_back(root->data);

        if (!root->left && !root->right)
        {
            return ans;
        }

        if (root->left)
            getLeft(root->left, ans);
        getChild(root, ans);
        if (root->right)
            getRight(root->right, ans);
        return ans;
    }
};