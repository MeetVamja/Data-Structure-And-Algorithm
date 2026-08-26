class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
      
        vector<int> graph[V];
        for(auto ed : edges){
            int v = ed[0];
            int u = ed[1];
            graph[v].push_back(u);
        }
        
        vector<int> indegree(V, 0);
        for(auto it : graph){
            for(auto node : it){
                indegree[node]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
          if(indegree[i] == 0){
              q.push(i);
          }
        }
        
        vector<int> res;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it : graph[front]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
            res.push_back(front);
        }
        return res;
    }
};
