class Solution {
  void dfs(int i, vector<int> adj[], vector<int> &res, unordered_map<int, bool> &visited){
      res.push_back(i);
      visited[i] = true;
      for(auto j:adj[i]){
          if(!visited[j]){
              dfs(j, adj, res, visited);
          }
      }
  }
  
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        unordered_map<int, bool> visited;
        dfs(0, adj, res, visited);
        return res;
    }
};