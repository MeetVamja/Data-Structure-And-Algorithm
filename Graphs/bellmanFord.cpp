// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 0; i < V - 1; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                // if dist[u] != 1e8 means then node should be reachable from source itself
                // if it is equal to 1e8 then it is not yet reachable from source
                if(dist[u] != 1e8 && (dist[u] + w < dist[v])){
                    dist[v] = dist[u] + w;
                }
            }
        }
        for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                // if dist[u] != 1e8 means then node should be reachable from source itself
                if(dist[u] != 1e8 &&( dist[u] + w < dist[v])){
                    return {-1};
                }
            }
            return dist;
    }
};
