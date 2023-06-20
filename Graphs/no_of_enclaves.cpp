// User function Template for C++

class Solution
{
public:
    int bfs(int n, int m, int row, int col, vector<vector<int>> &grid,
            vector<vector<int>> &visited)
    {

        queue<pair<int, int>> q; // {row,col}
        bool corner = false;
        q.push({row, col});
        visited[row][col] = 1;
        int size = 0;

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            size += 1;

            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, +1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    if (nrow == 0 || nrow == n - 1 || ncol == 0 || ncol == m - 1)
                        corner = true;
                }
            }
        }

        if (row == 0 || row == n - 1 || col == 0 || col == m - 1 || corner)
        {
            return 0;
        }
        return size;
    }

    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m));

        int enclaveSize = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    // cout<<i<<" "<<j<<endl ;
                    int temp = bfs(n, m, i, j, grid, visited);
                    enclaveSize += temp;
                }
            }
        }

        return enclaveSize;
    }
};