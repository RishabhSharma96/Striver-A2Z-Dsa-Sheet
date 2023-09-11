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
    int removeStones(vector<vector<int>>& stones) {
        
        int row = INT_MIN, col = INT_MIN;

        for(auto it : stones){
            row = max(row,it[0]);
            col = max(col,it[1]);
        }

        DisjointSet stoneNodes(row + col + 1) ;
        unordered_map<int,int> stoneConnections;

        for(auto it : stones){
            int nodeRow = it[0] ;
            int nodeCol = it[1] + row + 1;
            stoneNodes.unionBySize(nodeRow, nodeCol);
            stoneConnections[nodeRow] = 1 ;
            stoneConnections[nodeCol] = 1 ;
        }

        int n = stones.size() ;

        for(auto it : stoneConnections){
            if(stoneNodes.findUltimateParent(it.first) == it.first){
                --n ;
            }
        }

        return n ;

    }
};
