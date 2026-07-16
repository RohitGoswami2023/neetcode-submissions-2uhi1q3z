class Solution {
public:
    bool dfs(int src , int dst , vector<vector<int>> & graph , vector<bool>& visit ){
        visit[src] = true;
        bool reach = false ;
        if( src == dst ) return true;
        for( auto nei : graph[src]){
            if(!visit[nei]){
                reach = reach || dfs( nei , dst , graph , visit);
            }
        }
        return reach ;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph ( n);
        for (auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
        }
        vector<bool>visit(n , false);
        int q = queries.size();
        vector<bool>result(q);
        for (int i = 0 ; i< q ; i++){
            vector<bool>visit(n , false);

            int a = queries[i][0];
            int b = queries[i][1];
            
             result[i] =  dfs( a, b  , graph , visit);
            
        }

    return result;
    }
};