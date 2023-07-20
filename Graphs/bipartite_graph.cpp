class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int> & colors, int node, int color){
        colors[node] = color;

        for(auto it: graph[node]){
            if(colors[it] == -1){
                if(dfs(graph,colors,it,!color) == false){
                    return false;
                }
            }
            else{
                if(colors[it] == color){
                    return false;
                }
            }
        }
        return true ;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size() ;
        vector<int> colors(V,-1);

        for(int i=0 ; i<V; i++){
            if(colors[i] == -1){
                bool dfsCall = dfs(graph,colors,i,0);
                if(!dfsCall){
                    return false;
                }
            }
        }
        return true ;
    }
};