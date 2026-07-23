class Solution {
private:
    bool solve(string& s, int i, int minJump, int maxJump , vector<int>&dp) {
        if (i == s.length() - 1)
            return true;

        if (s.back() == '1')
            return false;
        if(dp[i] != - 1) return dp[i];

        for (int j = minJump; j <= maxJump; j++) {
            int jump = i + j;

            if (jump >= s.length())
                break;

            if (s[jump] == '0') {
                if (solve(s, jump, minJump, maxJump , dp))
                    return  dp[i] = true;
            }
        }

        return  dp[i] = false;
    }

public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int>dp(s.length() , -1);
        return solve(s, 0, minJump, maxJump , dp);
    }
};