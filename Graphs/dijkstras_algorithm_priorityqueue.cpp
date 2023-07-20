class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        vector<int> distance(V,1e8);
        distance[S] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second ;
            int dist = pq.top().first ;
            pq.pop() ;
            
            for(auto it : adj[node]){
                int adjNode = it[0] ;
                int weight = it[1] ;
                if(weight + dist < distance[adjNode]){
                    distance[adjNode] = weight + dist;
                    pq.push({weight + dist , adjNode});
                }
            }
        }
        return distance ;
    }
};