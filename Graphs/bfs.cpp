class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> result;
        int n = adj.size();
        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto ngbr : adj[node]){
                if(!vis[ngbr]){
                    vis[ngbr] = 1;
                    q.push(ngbr);
                }
            }
        }
        return result;
    }
};
