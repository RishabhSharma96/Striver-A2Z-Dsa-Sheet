// GFG
//  User function Template for C++

class Solution
{
public:
    void bfs(int node, vector<vector<int>> &newAdj, vector<int> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            for (auto it : newAdj[temp])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> newAdj(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    newAdj[i].push_back(j);
                }
            }
        }

        vector<int> visited(V, 0);
        int province = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                province++;
                bfs(i, newAdj, visited);
            }
        }
        return province;
    }
};








// LEETCODE
class Solution
{
public:
    void bfs(int node, vector<vector<int>> &newAdj, vector<int> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            for (auto it : newAdj[temp])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<vector<int>> newAdj(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    newAdj[i].push_back(j);
                }
            }
        }
        vector<int> visited(V, 0);
        int province = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                province++;
                bfs(i, newAdj, visited);
            }
        }
        return province;
    }
};