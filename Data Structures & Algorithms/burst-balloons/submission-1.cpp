class Solution {
private:

    int solve(int i, int j, vector<int>& balloons, vector<vector<int>>& dp){

        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for(int k = i; k <= j; k++){

            int left = solve(i, k-1, balloons, dp);

            int right = solve(k+1, j, balloons, dp);

            int current = balloons[i-1] * balloons[k] * balloons[j+1];

            ans = max(ans, left + right + current);
        }

        return dp[i][j] = ans;
    }

public:

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        vector<int> balloons;

        balloons.push_back(1);

        for(int x : nums)
            balloons.push_back(x);

        balloons.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        return solve(1, n, balloons, dp);
    }
};