class Solution {
public: 
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size() ;
        int m = heights[0].size() ;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq ; // for -> {distance,{row,col}};
        vector<vector<int>> distance(n , vector<int> (m , 1e9));
        vector<int> delrow = {-1,0,+1,0};
        vector<int> delcol = {0,+1,0,-1};

        distance[0][0] = 0 ;
        pq.push({0 , {0,0}});

        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop() ;
            
            if(row == n-1 && col == m-1){
                return dist;
            }

            for(int i=0 ; i<4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i] ;

                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int heightDiff = max(abs(heights[nr][nc] - heights[row][col]), dist);
                    if(heightDiff < distance[nr][nc]){
                        distance[nr][nc] = heightDiff;
                        pq.push({heightDiff, {nr,nc}});
                    }
                }
            }
        }

        return 0 ;
    }
};