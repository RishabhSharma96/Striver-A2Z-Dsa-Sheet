class Solution
{
public:
	// Function to return list containing vertices in Topological order.

	void dfs(vector<int> adj[], stack<int> &st, vector<int> &visited, int node)
	{
		visited[node] = 1;
		for (auto it : adj[node]){
			if (!visited[it]){
				dfs(adj, st, visited, it);
			}
		}
		st.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[]){
		vector<int> topoSort;
		stack<int> st;
		vector<int> visited(V, 0);

		for (int i = 0; i < V; i++){
			if (!visited[i]){
				dfs(adj, st, visited, i);
			}
		}

		while (!st.empty()){
			topoSort.push_back(st.top());
			st.pop();
		}

		return topoSort;
	}
};