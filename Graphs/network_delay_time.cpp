class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            int from = it[0] ;
            int to = it[1];
            int wt = it[2];
            adj[from].push_back({to,wt});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        // for -> {distn=ance,node}

        pq.push({0,k});
        vector<int> distance(n+1,1e8);
        distance[k] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second ;
            int dist = pq.top().first ;
            pq.pop() ;
            
            for(auto it : adj[node]){
                int adjNode = it.first ;
                int weight = it.second ;
                if(weight + dist < distance[adjNode]){
                    distance[adjNode] = weight + dist;
                    pq.push({weight + dist , adjNode});
                }
            }
        }

        int maxTime = INT_MIN ;
        for(int i=1 ; i<n+1 ; i++){
            if(distance[i] == 1e8){
                return -1;
            }
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime ;
    }
};