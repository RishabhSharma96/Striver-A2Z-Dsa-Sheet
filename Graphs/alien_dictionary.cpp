// User function Template for C++

class Solution{
    
    public:
    
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
    
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        
        for(int i=0 ; i<N-1 ; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int minLen = min(s1.size() , s2.size()) ;
            
            for(int i=0 ; i < minLen ; i++){
                if(s1[i] != s2[i]){
                    adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K,adj);
        string ans = "";
        
        for(auto it:topo){
            ans += it + 'a';
        }
        
        return ans;        
        
    }
};