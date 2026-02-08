class Solution {
public:
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& rec, stack<int>& st) {
        vis[v] = 1;
        rec[v] = 1;

        for (int it : graph[v]) {
            if (!vis[it] && dfs(it, graph, vis, rec, st))
                return true;
            else if (rec[it])
                return true;
        }

        rec[v] = 0;
        st.push(v);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        ;
        for (auto edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
        }
      // rec is used to maintian the path, if we encounter any vertex and if the neighbour of that vertex is already vis and it is also belong to the same path then we have a cycle
      // other part of code is to find the topological sorting using dfs and it is stored in stack.
        vector<int> vis(numCourses, 0), rec(numCourses, 0);
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, graph, vis, rec, st))
                    return {};
            }
        }
        vector<int> res;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            res.push_back(node);
        }
        return res;
    }
};
