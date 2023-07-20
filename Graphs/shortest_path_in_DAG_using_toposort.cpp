// User function Template for C++
class Solution {
  public:
  
    void toposort(stack<int> & st, vector<pair<int,int>> adj[], int node, vector<int> & visited){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it.first]){
                toposort(st,adj,it.first,visited);
            }
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back({it[1],it[2]}); 
        }
        
        stack<int>st ;
        vector<int> visited(N,0);
        for(int i=0 ; i<N ; i++){
            if(!visited[i]){
                toposort(st,adj,i,visited);
            }
        }
        
        vector<int> distance(N,1e8);
        distance[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop() ;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                if(weight + distance[node] < distance[adjNode]){
                    distance[adjNode] = weight + distance[node];
                }
            }
        }
        
        for(int i=0 ; i<N ; i++){
            if(distance[i] == 1e8){
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};