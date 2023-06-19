class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[])
    {

        vector<vector<int>> newAdj;

        for (int i = 0; i < V; i++)
        {
            adj[i].insert(adj[i].begin(), i);
            newAdj.push_back(adj[i]);
        }

        return newAdj;
    }
};