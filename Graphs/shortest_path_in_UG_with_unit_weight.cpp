// User function Template for C++
class Solution {
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        
        queue<pair<int,int>> q ;
        q.push({src,0});
        vector<int> visited(N,0);
        vector<int> distance(N,-1);
        distance[src] = 0;
        visited[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first ;
            int dist = q.front().second;
            q.pop();
            distance[node] = dist ;
            
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push({it,dist+1});
                    visited[it] = 1;
                }
            }
        }
        return distance;
    }
};