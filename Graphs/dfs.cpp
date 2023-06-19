class Solution
{
public:
    void dfs(auto node, vector<int> adj[], vector<int> &visited, vector<int> &ans)
    {
        ans.push_back(node);
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                dfs(it, adj, visited, ans);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> ans;
        dfs(0, adj, visited, ans);
        return ans;
    }
};