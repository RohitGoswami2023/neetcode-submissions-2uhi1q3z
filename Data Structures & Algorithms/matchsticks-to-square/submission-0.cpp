class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        
        
        for (int s : matchsticks) {
            sum += s; 
        }
        
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        int total = 1 << n;
        
        vector<int> dp(total, -1);
        dp[0] = 0;
        
        
        for (int i = 0; i < total; i++) {
            if (dp[i] == -1) continue;
            
            for (int j = 0; j < n; j++) {
                if (!(i & (1 << j))) {
                    if (dp[i] + matchsticks[j] <= target) {
                        int next = i | (1 << j);
                        dp[next] = (dp[i] + matchsticks[j]) % target;
                    }
                }
            }
        }
        
        return dp[total - 1] == 0;
    }
};