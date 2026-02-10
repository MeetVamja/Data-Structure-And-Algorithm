class Solution {
  public:
    vector<int>parent;
    vector<int> rank;
    
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y) return;
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
        
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        parent.resize(V);
        rank.resize(V);
        for(int i = 0;i < V; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.back() < b.back();   // sort by last element
    });
        int sum = 0;
        int cnt = 1;
        int i = 0;
        while(cnt < V){
            auto temp = edges[i++];
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            if(find(u) != find(v)){
                Union(u,v);
                sum+=wt;
                cnt++;
            }
        }
        return sum;
    }
};
