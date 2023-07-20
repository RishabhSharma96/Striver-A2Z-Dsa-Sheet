class Solution {
public:
    int solve(vector<vector<int>>& grid,pair<int,int>s,pair<int,int>d){

        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1] == 1) return -1;

        if(s.first == d.first && s.second == d.second) return 1;
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        dist[0][0]=1;
        queue<pair<int,pair<int,int>>>q;
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};
        q.push({1,{0,0}});
        while(q.empty()==false){
            auto it=q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    if(nr==d.first && nc==d.second){
                        return dis+1;
                    }
                    q.push({1+dis,{nr,nc}});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int,int>s={0,0};
        pair<int,int>d={n-1,n-1};
        return solve(grid,s,d);
    }
};