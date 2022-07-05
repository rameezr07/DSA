class Solution{
	public:
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector <int> res(V, 100000000);
        res[S] = 0;
        for(int i=0; i<V-1; i++){
            for(auto e: adj){
                // If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
                // dist[v] = dist[u] + weight of edge uv
                int u = e[0], v = e[1], w = e[2];
                if(res[v] > res[u] + w)
                    res[v] = res[u] + w;
            }
        }
        return res;
    }
};