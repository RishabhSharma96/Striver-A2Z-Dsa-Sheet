class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &grid, int sr, int sc, int newColor)
    {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q; // {row,col}
        vector<vector<int>> visited(n, vector<int>(m, 0));
        q.push({sr, sc});
        visited[sr][sc] = 1;
        int prevColor = grid[sr][sc];
        grid[sr][sc] = newColor;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == prevColor && visited[nr][nc] == 0)
                {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                    grid[nr][nc] = newColor;
                }
            }
        }
        return grid;
    }
};