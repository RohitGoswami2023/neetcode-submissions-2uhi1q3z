class Solution {
private:
    void dfs(unordered_map<string, vector<pair<string, double>>>& graph, 
             string src, string dst, 
             unordered_set<string>& visited, 
             double product, double& ans) {
        
        if (visited.find(src) != visited.end()) return;
        
        visited.insert(src);
        
        if (src == dst) {
            ans = product; 
            return;
        }
        
        for (auto& p : graph[src]) {
            string neighbor = p.first;
            double val = p.second;
            dfs(graph, neighbor, dst, visited, product * val, ans);
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }
        
        vector<double> result;
        
        for (auto& query : queries) {
            string src = query[0];
            string dst = query[1];
            double ans = -1.0;
            double product = 1.0;
            
            if (graph.find(src) != graph.end() && graph.find(dst) != graph.end()) {
                unordered_set<string> visited;
                dfs(graph, src, dst, visited, product, ans);
            }
            
            result.push_back(ans);
        }
        
        return result;
    }
};