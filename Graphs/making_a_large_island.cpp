class DisjointSet{ 
    
    public:

    vector<int> rank, parent;
    vector<int> size;

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
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size() ;
        DisjointSet ds(n*n) ;

        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};

        // connected the components
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    int row = i ;
                    int col = j ;
                    for(int neighbour=0 ; neighbour<4 ; neighbour++){
                        int nrow = row + dr[neighbour];
                        int ncol = col + dc[neighbour];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 1){
                            int rowNode = row * n + col ;
                            int adjRowNode = nrow * n + ncol ;
                            ds.unionBySize(rowNode,adjRowNode);
                        }
                    }
                }
            }
        }

        // counting the max size of compponents by checking neighbours
        int maxSize = 0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                int row = i ;
                int col = j ;
                unordered_set<int> sizeOfNeighbours ;
                if(grid[i][j] == 0){
                    for(int neighbour=0 ; neighbour<4 ; neighbour++){
                        int nrow = row + dr[neighbour];
                        int ncol = col + dc[neighbour];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 1){
                            sizeOfNeighbours.insert(ds.findUltimateParent(nrow*n+ncol));
                        }
                    }
                }
                int newSize = 0;
                for(auto it : sizeOfNeighbours){
                    newSize += ds.size[it];
                }
                maxSize = max(maxSize,newSize+1);
            }
        }

        // check if all are 1 in grid
        for(int i=0 ; i<n*n ; i++){
            maxSize = max(maxSize,ds.size[ds.findUltimateParent(i)]);
        }

        return maxSize ;
    }
};