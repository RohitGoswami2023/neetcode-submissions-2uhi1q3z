class Solution {
   private:
    bool cycle(int node, int parent, vector<vector<int>>& graph, vector<bool>& visit) {
        visit[node] = true;
        for (auto nei : graph[node]) {
            if (!visit[nei]) {
                if (cycle(nei, node, graph, visit)) return true;
            } else if (nei != parent)
                return true;
        }

        return false;
    }

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n);
        vector<bool> visit(n, false);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (cycle(0, -1, graph, visit)) return false;

        for (int i = 0; i < n; i++) {
            if (!visit[i]) return false;
        }

        return true;
    }
};
