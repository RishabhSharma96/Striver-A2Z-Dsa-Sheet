class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        st.insert({0,S});
        vector<int> distance(V,1e8);
        distance[S] = 0;
        
        while(!st.empty()){
            auto iterator = *(st.begin());
            int node = iterator.second ;
            int dist = iterator.first ;
            st.erase(iterator) ;
            
            for(auto it : adj[node]){
                int adjNode = it[0] ;
                int weight = it[1] ;
                if(weight + dist < distance[adjNode]){
                    distance[adjNode] = weight + dist;
                    st.insert({weight + dist , adjNode});
                }
            }
        }
        return distance ;
    }
};