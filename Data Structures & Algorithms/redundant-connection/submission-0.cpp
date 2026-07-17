class Solution {
public:

    bool dfs(int src, int dst,
             vector<vector<int>>& graph,
             vector<bool>& vis)
    {
        if(src == dst)
            return true;

        vis[src] = true;

        for(int nbr : graph[src])
        {
            if(!vis[nbr])
            {
                if(dfs(nbr, dst, graph, vis))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();

        vector<vector<int>> graph(n + 1);

        for(auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            vector<bool> vis(n + 1, false);

            if(!graph[u].empty() && !graph[v].empty())
            {
                if(dfs(u, v, graph, vis))
                    return it;
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};