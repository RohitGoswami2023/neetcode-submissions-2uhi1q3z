class Solution {
public:
    int n, m;
    vector<vector<int>> direc = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<int>>& heights,
             int i,
             int j,
             int prev,
             vector<vector<bool>>& visit) {

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (visit[i][j])
            return;

        if (heights[i][j] < prev)
            return;

        visit[i][j] = true;

        for (auto &d : direc) {
            dfs(heights,
                i + d[0],
                j + d[1],
                heights[i][j],
                visit);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> Pacific(n, vector<bool>(m, false));
        vector<vector<bool>> Atlantic(n, vector<bool>(m, false));

        vector<vector<int>> result;

        for (int j = 0; j < m; j++) {
            dfs(heights, 0, j, INT_MIN, Pacific);
            dfs(heights, n - 1, j, INT_MIN, Atlantic);
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, i, 0, INT_MIN, Pacific);
            dfs(heights, i, m - 1, INT_MIN, Atlantic);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (Pacific[i][j] && Atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};