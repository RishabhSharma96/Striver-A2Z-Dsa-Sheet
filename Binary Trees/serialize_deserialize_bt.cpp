// istringstream info

	// Input string
	string a("1 2 3");

	// Object class of istringstream
	istringstream my_stream(a);

	// Variable to store number n
	int n;

	// Stream a number till white space
	// is encountered
	my_stream >> n;

	// Print the number
	cout << n << "\n";

    // copies the element in ss to a string variable s
    string s;
    ss >> s;




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeHelper(TreeNode* root, string & s){
        if(!root){
            s += "# ";
            return ;
        }
        s += to_string(root->val) + " ";
        serializeHelper(root->left,s);
        serializeHelper(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        serializeHelper(root,ans);
        cout<<ans;
        return ans;
    }

    TreeNode* deserializeHelper(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "#")
			return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
            
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));