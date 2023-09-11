// User function Template for C++

class DisjointSet{ 
    
    vector<int> rank, parent;
    vector<int> size;

    public:

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v){
            return;
        }
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v){
            return ;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<vector<int>> visited(n, vector<int> (m, 0));
        DisjointSet ds(n*m);
        vector<int> ans ;
        vector<int> drow = {-1,0,+1,0} ;
        vector<int> dcol = {0,+1,0,-1} ;
        int islands = 0;
        
        for(auto it : operators){
            
            int row = it[0] ;
            int col = it[1] ;
            
            if(visited[row][col] == 1){
                ans.push_back(islands);
                continue ;
            }
            
            visited[row][col] = 1;
            islands++ ;
            
            for(int i= 0 ; i<4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    if(visited[nrow][ncol] == 1){
                        int nodeNo = row*m + col;
                        int adjNodeNo = nrow*m + ncol;
                        if(ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo)){
                            ds.unionBySize(nodeNo,adjNodeNo);
                            islands--;
                        }
                    }
                }
                
            }
            ans.push_back(islands);
        }
        
        return ans;
    }
};