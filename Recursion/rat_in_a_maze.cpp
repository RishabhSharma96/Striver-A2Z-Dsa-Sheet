// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> & maze, vector<vector<int>> & visited, vector<string> &ans, int n, int row,int col, string helper){
        if(row == n-1 && col == n-1){
            ans.push_back(helper);
            return ;
        }
        
        if(row+1<n && maze[row+1][col] == 1 && visited[row+1][col] == 0){
            visited[row][col] = 1;
            solve(maze,visited,ans,n,row+1,col,helper+"D");
            visited[row][col] = 0;
        }
        
        if(col+1<n && maze[row][col+1] == 1 && visited[row][col+1] == 0){
            visited[row][col] = 1;
            solve(maze,visited,ans,n,row,col+1,helper+"R");
            visited[row][col] = 0;
        }
        
        if(col-1>=0 && maze[row][col-1] == 1 && visited[row][col-1] == 0){
            visited[row][col] = 1;
            solve(maze,visited,ans,n,row,col-1,helper+"L");
            visited[row][col] = 0;
        }
        
        if(row-1>=0 && maze[row-1][col] == 1 && visited[row-1][col] == 0){
            visited[row][col] = 1;
            solve(maze,visited,ans,n,row-1,col,helper+"U");
            visited[row][col] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<vector<int>> visited(n , vector<int> (n, 0));
        vector<string> ans ;
        
        if(maze[0][0] == 1){
            solve(maze,visited,ans,n,0,0,"");
        }
        
        return ans;
    }
};