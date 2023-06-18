// Function to search a node in BST.

void solve(Node *root, int &ans, int input)
{
    if (!root)
        return;

    if (0 < ans && root->data <= input)
    {
        ans = root->data;
    }
    if (root->data > input)
    {
        solve(root->left, ans, input);
    }
    else
    {
        solve(root->right, ans, input);
    }
}

int floor(Node *root, int input)
{
    int ans = 1e8;
    solve(root, ans, input);
    return ans == 1e8 ? -1 : ans;
}