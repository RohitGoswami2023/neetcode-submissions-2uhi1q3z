class Solution {
public:
    bool isMatch(string s, string p) {
       int n = s.length();
       int m = p.length();
       vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
       
       dp[0][0] = true;
       
       for (int j = 1; j <= m; j++) {
           char ch_p = p[j - 1];
           if (ch_p == '*') {
               dp[0][j] = dp[0][j - 2];
           }
       }
       
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
               char ch_at_P = p[j - 1]; 
               char ch_at_S = s[i - 1]; 
               
               if (ch_at_P == '*') {
                   dp[i][j] = dp[i][j - 2]; 
                   
                   char prev_P = p[j - 2]; 
                   if (prev_P == '.' || prev_P == ch_at_S) {
                       dp[i][j] = dp[i][j] || dp[i - 1][j]; 
                   }
               }
               else if (ch_at_P == '.' || ch_at_S == ch_at_P) {
                   dp[i][j] = dp[i - 1][j - 1];
               }
               else {
                   dp[i][j] = false;
               }
           }
       }
       return dp[n][m];
    }
};