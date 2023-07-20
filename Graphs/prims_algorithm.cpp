class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq ; // for -> {weight,node}
        vector<int> visited (V , 0);
        
        pq.push({0,0});
        int sum = 0 ;
        
        while(!pq.empty()){
            int node = pq.top().second ;
            int weight = pq.top().first ;
            pq.pop();
            
            if(visited[node]){
                continue ;
            }
            
            // ⭐ if required mst push {node,parent} here into mst vector and then pq configuration will be {weight,{node,parent}} 
            visited[node] = 1 ;
            sum += weight ;
            
            for(auto it : adj[node]){
                int adjNode = it[0] ;
                int edgeWeight = it[1] ;
                
                if(!visited[adjNode]){
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        
        return sum ;
    }
};
