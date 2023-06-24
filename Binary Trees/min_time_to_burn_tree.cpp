//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    void getParent(Node* root, unordered_map<Node*,Node*> & parent){

        queue<Node*> q ;
        q.push(root);
        parent[root] = NULL;

        while(!q.empty()){
            auto node = q.front() ;
            q.pop();

            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;  
            }
        }
    }
    
    Node* getNode (Node* root,int target){
        if(!root) return NULL;
        if(root->data == target) return root;
        
        Node* left = NULL;
        if(root->left){
            left = getNode(root->left,target);
        }
        Node* right = NULL;
        if(root->right){
            right = getNode(root->right,target);
        }
        
        if(left && !right) return left;
        if(right && !left) return right;
        return NULL;
    }
  
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parent;
        getParent(root,parent);
        
        unordered_map<Node*, bool> visited;
        queue<pair<Node*,int>> q ;
        Node* targetNode = getNode(root,target);
        q.push({targetNode,0});
        visited[targetNode] = true;

        int time = 0 ;

        while(!q.empty()){

            auto node = q.front().first;
            auto curr_time = q.front().second;
            q.pop();

            time = max(time,curr_time);


            if(node->left && visited[node->left] == false){
                q.push({node->left,curr_time+1});
                visited[node->left] = true;
            }
            if(node->right && visited[node->right] == false){
                q.push({node->right,curr_time+1});
                visited[node->right] = true;
            }
            if(parent[node] && visited[parent[node]] == false){
                q.push({parent[node],curr_time+1});
                visited[parent[node]] = true;
            }
        }
        
        return time;
    }
};