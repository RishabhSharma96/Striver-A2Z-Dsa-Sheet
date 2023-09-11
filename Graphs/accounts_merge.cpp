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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size() ;
        DisjointSet ds(n);
        unordered_map<string,int> mp ;

        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<accounts[i].size() ; j++){
                string email = accounts[i][j] ;
                if(mp.find(email) == mp.end()){
                    mp[email] = i ;
                }
                else{
                    ds.unionBySize(i,mp[email]);
                }
            }
        } 

        vector<string> tempAns[n] ;

        for(auto it : mp){
            string email = it.first;
            int node = ds.findUltimateParent(it.second);
            tempAns[node].push_back(email);
        }

        vector<vector<string>> ans ;

        for(int i=0 ; i<n ; i++){
                if(tempAns[i].size() != 0){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(tempAns[i].begin() , tempAns[i].end());

                for(auto it : tempAns[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};