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
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n) ;
        int extraCables = 0;

        for(auto it : connections){
            if(ds.findUltimateParent(it[0]) == ds.findUltimateParent(it[1])){
                extraCables++ ;
            }
            else{
                ds.unionByRank(it[0] , it[1]);
            }
        }

        int unjoinedComponents = 0;
        for(int i=0 ; i<ds.parent.size()-1 ; i++){
            if(ds.parent[i] == i){
                unjoinedComponents++ ;
            }
        }

        return extraCables >= unjoinedComponents-1 ? unjoinedComponents-1 : -1;

    }
};