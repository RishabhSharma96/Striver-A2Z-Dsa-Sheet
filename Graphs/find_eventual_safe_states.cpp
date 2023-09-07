class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size() ;

        vector<int> adjRev[n] ;
        vector<int> indegree(n,0);
        queue<int> q ;
        vector<int> safe ;

        for(int i=0 ; i<n ; i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;

            safe.push_back(node);

            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;

    }
};