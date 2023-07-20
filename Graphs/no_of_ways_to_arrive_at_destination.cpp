class Solution {
public:

    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n] ;
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
        greater<pair<long long, long long>>> pq;
        vector<long long> distance(n, 1e15), ways(n, 0);

        pq.push({0,0});
        ways[0] = 1 ;
        distance[0] = 0 ;

        while(!pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long weight = it.second ;

                if(weight + dist < distance[adjNode]){
                    distance[adjNode] = weight + dist;
                    pq.push({weight + dist,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(weight + dist == distance[adjNode]){
                    // pq.push({weight + dist,adjNode});
                    ways[adjNode] = (ways[adjNode]%mod + ways[node]%mod)%mod;
                }
            }
        }

        return ways[n-1];
    }
};