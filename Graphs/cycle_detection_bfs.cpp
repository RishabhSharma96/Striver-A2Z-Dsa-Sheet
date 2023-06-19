class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        queue<pair<int, int>> q; // {node,parent}

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {

            q.push({i, -1});
            visited[i] = 1;

            while (!q.empty())
            {
                auto temp = q.front();
                q.pop();
                int node = temp.first;
                int parent = temp.second;

                for (auto it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push({it, node});
                        visited[it] = 1;
                    }
                    else
                    {
                        if (it != parent)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};