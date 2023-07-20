class Solution {
public:

    vector<int> toposort(vector<int> adj[], int V){
        vector<int> visited(V,0);
        vector<int> topo;
        vector<int> indegree(V);
        queue<int> q ;

        for(int i=0 ; i<V ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0 ; i<V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front() ;
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]-- ;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return topo;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]) ;
        }

        vector<int> topo = toposort(adj,numCourses);

        if(topo.size() == numCourses){
            return true ;
        }
        return false;
    }
};