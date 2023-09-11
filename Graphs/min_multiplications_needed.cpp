// User function Template for C++

class Solution {
  public:
  
    const int mod = 100000 ;
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        vector<int> distance (100000, INT_MAX) ;
        queue<pair<int,int>> q ; // for -> {node,steps_for_multiplication}
        q.push({start,0});
        distance[start] = 0 ;
        
        while(!q.empty()){
            
            int node = q.front().first;
            int steps = q.front().second;
            q.pop() ;
            
            if(node == end){
                return steps ;
            }
            
            for(auto it : arr){
                int new_node = (it*node)%mod ;
                if(steps + 1 < distance[new_node]){
                    distance[new_node] = steps + 1 ;
                    q.push({new_node, steps + 1});
                }
            }
            
        }
        return -1;
    }
};