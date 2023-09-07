// User function Template for C++

class Solution {
  public:
  
    void dfs(int row, int col, vector<pair<int,int>> & helper, vector<vector<int>>& grid, vector<vector<int>> & visited, int baseRow, int baseCol){
        visited[row][col] = 1;
        
        int drow[] = {-1,0,+1,0} ;
        int dcol[] = {0,-1,0,+1} ;
        
        helper.push_back({row-baseRow , col-baseCol});
        
        for(int i=0 ; i<4 ; i++){
            int dr = row + drow[i] ;
            int dc = col + dcol[i] ;
            
            if(dr>=0 && dr<grid.size() && dc>=0 && dc<grid[0].size() && visited[dr][dc] == 0 && grid[dr][dc] == 1){
                dfs(dr,dc,helper,grid,visited,baseRow,baseCol);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int> (m,0)) ;
        set<vector<pair<int,int>>> st ;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    vector<pair<int,int>> helper ;
                    dfs(i,j,helper,grid,visited,i,j);
                    st.insert(helper);
                }
            }
        }
        return st.size();
    }
};