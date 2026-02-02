class Solution {
  public:
    void dfs(vector<int>& ans ,vector<int>& vis, vector<vector<int>>& adj, int node){
        vis[node] = 1;
        ans.push_back(node);
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                dfs(ans,vis, adj, ngbr);
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        int n = adj.size();
        vector<int> vis(n, 0);
        dfs(ans,vis,adj, 0);
        return ans;
    }
};
