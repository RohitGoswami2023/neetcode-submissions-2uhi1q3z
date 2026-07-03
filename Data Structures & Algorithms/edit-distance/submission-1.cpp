class Solution {
private: 
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        // Correct base cases: return the actual count of remaining characters
        if (i < 0) return j + 1; 
        if (j < 0) return i + 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
        }
        
        int insert  = solve(s1, s2, i, j - 1, dp);
        int remove  = solve(s1, s2, i - 1, j, dp);
        int replace = solve(s1, s2, i - 1, j - 1, dp);
        
        return dp[i][j] = 1 + min({insert, remove, replace});
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, n - 1, m - 1, dp);
    }
};