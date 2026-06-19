vector<int> dp(59);

class Solution {
public:
    Solution() {
            
        dp[1] = dp[2] = 1;
        for (int i = 3; i < 59; i++)
            integer_break(i);
    }

public:
    int integerBreak(int N) {

        return dp[N];        
    }
private:
    int integer_break(int N) {

        if (N == 1 || N == 2)
            return 1;
        
        if (dp[N]) 
            return dp[N];

        int max = INT_MIN;

        for (int i = 0; i < N / 2; i++)
        {
            int x = 1, y = N - 1;
            while (x <= y)
            {
                max = fmax(x * y, fmax(x * integer_break(y), max));
                x ++;
                y --;
            }
        }

        return dp[N] = max;
    }
};