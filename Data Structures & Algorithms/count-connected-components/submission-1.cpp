class Solution {
public:
    void dfs( int node , vector<vector<int>> & graph , vector<bool> & visit){
        visit[node] = true;
        for ( int neig : graph[node]){
            if(!visit[neig]){
                dfs(neig , graph ,visit);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for( auto& it : edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int component = 0 ;
        vector<bool>visit( n , false);
        for ( int i = 0 ;i< n ; i++){
            if(!visit[i]){
                component++;
                dfs( i , graph , visit);
            }
        }
        return component;
    }
};
