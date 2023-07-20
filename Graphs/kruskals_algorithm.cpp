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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges ;
        
        for(int i=0 ; i< V ; i++){
            for(auto it : adj[i]){
                int adjNode = it[0] ;
                int weight = it[1] ;
                
                edges.push_back({weight , {i , adjNode}});
            }
        }
        
        sort(edges.begin() , edges.end()) ;
        
        DisjointSet ds (V) ;
        
        int ans = 0;
        
        for(auto it : edges){
            int u = it.second.first ;
            int v = it.second.second ;
            int weight = it.first ;
            
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                ans += weight ;
                ds.unionByRank(u,v);
            }
        }
        return ans ;
    }
};