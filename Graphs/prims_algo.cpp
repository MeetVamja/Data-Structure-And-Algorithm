class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> graph[V]; // {node, weight}
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;
        q.push({0,0});
        vector<bool> isMST(V,false);
        int sum = 0;
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int wt = p.first;
            int node = p.second;
            
            if(isMST[node]) continue;
            sum+= wt;
            
            for(auto adj : graph[node]){
                int neigh = adj.first;
                int weight = adj.second;
                
                if(isMST[neigh] == false){
                    q.push({weight, neigh});
                }
            }
            isMST[node] = true;
        }
        return sum;
    }
};
