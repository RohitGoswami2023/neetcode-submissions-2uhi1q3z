class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int> , int >> q;
        int fresh =  0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({{i, j} , 0});
                if( grid[i][j] == 1) fresh++;
            }
        }
        if( fresh == 0) return 0;
        int minute = 0 ;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [direction , t ] = q.front();
            auto [r , c] = direction ;
            q.pop();
            minute = t ;
            for (auto d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                q.push({{nr, nc} , minute+1});

                }
            }
        }
        return (fresh == 0 ) ? minute : -1 ;
    }
};
