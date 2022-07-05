class Solution {
public:
    vector<int> graphBFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        vector<int> res;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    visited[u] = true;
                    res.push_back(u);
                    for(auto v:graph[u]){
                        if(!visited[v]){
                            q.push(v);
                        }
                    }
                }
            }
        }
        return res;
    }
};