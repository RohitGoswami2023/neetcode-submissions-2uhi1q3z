class Solution {
public:
    int numSquares(int N) {
        
        vector<int> dp(N + 1, -1);
        return perfect_squares(N, dp);
    }

private:
    int perfect_squares(int N, vector<int>& dp) {

        if (N == 1)
            return 1;

        if (N == 0)
            return 0;

        if (dp[N] != -1)
            return dp[N];
        
        int min = N;
        for (int i = 1; i * i <= N; i++)
            min = fmin(min, 1 + perfect_squares(N - i * i, dp));

        return dp[N] = min;
    }
};