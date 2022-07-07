class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<int> indegree(V+1, 0);
	    for(int i=0; i<V; i++){
	        for(int j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
	    while(!q.empty()){
            int u = q.front(); q.pop();
            res.push_back(u);
            for(int v:adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        return res;
	}
};