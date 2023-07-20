class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            int from = it[0] ;
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to,price});
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,         
        greater<pair<int,pair<int,int>>>> pq;            // for -> {cost,{node,stops}}
        // queue<pair<int,pair<int,int>>> pq;                  // for -> {cost,{node,stops}}
        vector<int> distance(n,1e9);

        pq.push({0,{src,0}});
        distance[src] = 0;

        while(!pq.empty()){

            int node = pq.top().second.first;
            int cost = pq.top().second.second;
            int stops = pq.top().first;
            pq.pop() ;

            if (stops > k){
                continue;
            }

            for(auto it : adj[node]){
                int adjNode = it.first;
                int price = it.second ;

                if(cost + price < distance[adjNode]){
                    distance[adjNode] = cost + price;
                    pq.push({stops+1,{adjNode,cost+price}});
                }
            }

        }

        return distance[dst] == 1e9 ? -1 : distance[dst];

    }
};