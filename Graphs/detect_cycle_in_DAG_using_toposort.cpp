class Solution {
    
  public:
  
  int topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    queue<int> q;
	    vector<int> topo;
	    
	    for(int i=0 ; i<V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++ ;
	        }
	    }
	    
	    for(int i=0 ; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i) ;
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front() ;
	        q.pop() ;
	        topo.push_back(node);
	        
	        for(auto it: adj[node]){
	            indegree[it]-- ;
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    return topo.size() ;
	}
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // cout<<topoSort(V,adj)<<endl ;
        if(topoSort(V,adj) == V){
            return false;
        }
        return true;
    }
};