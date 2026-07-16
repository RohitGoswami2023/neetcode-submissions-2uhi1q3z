class Solution {
public:
    bool cycle( int node , vector<vector<int>> & graph , vector<bool> & visit , vector<int> & path , vector<int> & ans){
        visit[node] = true;
        path[node ] = 1;
        for( auto nei : graph[node]){
            if(!visit[nei]){
                if(cycle(nei , graph , visit , path , ans )) return true;
            }
            else if( path[nei]) return true;
        }
        path[node] = 0 ;
        ans.push_back(node);
        return false;

    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(n);
        vector<bool>visit( n, false);
        vector<int>path( n ,  0);
        for( auto & it : prerequisites){
            int u = it[0];
            int v = it[1];
            graph[v].push_back(u);
        }
        vector<int>ans;
        for( int i = 0 ; i< n ; i++){
            if(!visit[i]){
                if(cycle(i , graph , visit , path , ans)) return {};
            }
        }
        reverse(ans.begin()  , ans.end());
        return ans;
    }
};
