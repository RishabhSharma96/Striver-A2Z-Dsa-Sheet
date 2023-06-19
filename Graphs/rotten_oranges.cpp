class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q; // {{row,col},time}
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 0)
                {
                    visited[i][j] = 1;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        int time = 0;

        while (!q.empty())
        {
            auto node = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int tempTime = node.second;
            q.pop();
            time = max(time, tempTime);

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && visited[nr][nc] == 0)
                {
                    visited[nr][nc] = 1;
                    q.push({{nr, nc}, tempTime + 1});
                    grid[nr][nc] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};