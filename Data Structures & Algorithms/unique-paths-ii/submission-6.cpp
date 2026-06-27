#include <vector>
#include <iostream>

using namespace std;

class Solution {
private: 
    const int mod = 1e9 + 7;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        
        if (Grid[0][0] == 1 || Grid[n-1][m-1] == 1) return 0;
        
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
        dp[0][0] = 1; 
        
        for(int i = 1; i < n; i++){
            if(Grid[i][0] == 0) dp[i][0] = dp[i - 1][0];
            else dp[i][0] = 0;
        }
        
        for(int i = 1; i < m; i++){
            if(Grid[0][i] == 0) dp[0][i] = dp[0][i - 1];
            else dp[0][i] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(Grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = ( 1LL *dp[i-1][j] + dp[i][j-1]); 
                }
            }
        }

        return (int) dp[n - 1][m - 1];
    }
};