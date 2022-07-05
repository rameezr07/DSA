#include<unordered_map>
#include<list>
#include<set>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> s;
    dist[source] = 0;
    
    s.insert({0, source});
    
    while(!s.empty()){
        auto top = *(s.begin());
        
        int distance = top.first;
        int node = top.second;
        
        s.erase(s.begin());
        
        for(auto neighbour: adj[node]){
            if(distance + neighbour.second < dist[neighbour.first]){
                auto record = s.find({dist[neighbour.first], neighbour.first});
                if(record != s.end())
                    s.erase(record);
                dist[neighbour.first] = distance + neighbour.second;
                s.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
    return dist;
}
