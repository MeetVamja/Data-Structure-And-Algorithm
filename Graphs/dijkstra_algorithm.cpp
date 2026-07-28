class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
       vector<int> dist(V, 1e6);
       dist[src] = 0;
       vector<pair<int,int>> graph[V];
       for(auto edge : edges){
           int u = edge[0];
           int v = edge[1];
           int w = edge[2];
           graph[u].push_back({v, w});
           graph[v].push_back({u, w});
       }
       
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0, src});
       
       vector<int> processed(V);
       while(!pq.empty()){
           auto temp = pq.top();
           pq.pop();
           auto node = temp.second;
           auto distance = temp.first;
           
           if(processed[node]){
               continue;
           }
           processed[node] = 1;
           
           for(auto adj : graph[node]){
               if(distance + adj.second < dist[adj.first]){
                   dist[adj.first] = distance + adj.second;
                   pq.push({dist[adj.first], adj.first});
               }
           }
       }
       return dist;
        
    }
};
