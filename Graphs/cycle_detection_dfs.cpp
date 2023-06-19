class Solution
{
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                bool dfsCall = dfs(it, node, adj, visited);
                if (dfsCall)
                    return true;
            }
            else
            {
                if (parent != it)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool dfsCall = dfs(i, -1, adj, visited);
                if (dfsCall)
                    return true;
            }
        }
        return false;
    }
};