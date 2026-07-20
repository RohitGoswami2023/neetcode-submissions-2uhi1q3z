class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        auto safe = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        
        vector<vector<int>> result(n, vector<int>(m, 1e9));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            int diff = pq.top().first;
            auto cord = pq.top().second;
            pq.pop();
            
            int x = cord.first;
            int y = cord.second;
            
            for (int i = 0; i < dir.size(); i++) {
                int x_ = x + dir[i][0];
                int y_ = y + dir[i][1];
                
                if (safe(x_, y_)) {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);
                    
                    if (result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        return result[n - 1][m - 1];
    }
};