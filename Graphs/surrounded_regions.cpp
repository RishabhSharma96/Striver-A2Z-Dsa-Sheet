// User function Template for C++

class Solution
{
public:
    void dfs(int n, int m, int row, int col, vector<vector<char>> &mat, vector<vector<int>> &visited)
    {
        visited[row][col] = 1;

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] == 0 &&
                mat[nr][nc] == 'O')
            {
                dfs(n, m, nr, nc, mat, visited);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((j == 0 || j == m - 1 || i == 0 || i == n - 1) && mat[i][j] == 'O')
                {
                    if (!visited[i][j])
                    {
                        dfs(n, m, i, j, mat, visited);
                    }
                }
            }
        }

        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         cout<<visited[i][j] <<" ";
        //     }
        //     cout<<endl ;
        // }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};