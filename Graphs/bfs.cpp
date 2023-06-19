class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            bfs.push_back(temp);

            for (auto it : adj[temp])
            {
                if (visited[it] == 0)
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return bfs;
    }
};