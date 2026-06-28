#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    int recursive(int curr, int i, vector<int>& stones, int total, vector<vector<int>>& dp) {
        int n = stones.size();
        
        // Base Case: Jab saare stones scan ho chuke hon (i == n)
        if (i == n) {
            return abs(total - 2 * curr); // Dono groups ka absolute difference return karo
        }
        
        // Memoization Check: Agar is state ka answer pehle se pata hai
        if (dp[i][curr] != -1) {
            return dp[i][curr];
        }
        
        // Choice 1: Take the current stone
        int take = recursive(curr + stones[i], i + 1, stones, total, dp);
        
        // Choice 2: Skip the current stone
        int skip = recursive(curr, i + 1, stones, total, dp);
        
        // Dono choices me se jo minimum difference laaye, use save karo
        return dp[i][curr] = min(take, skip);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for (int stone : stones) total += stone; // Total sum nikaala
        
        // dp array ka size: [n][total + 1] initialized with -1
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        
        // Recursion shuru kiya curr = 0 aur index i = 0 se
        return recursive(0, 0, stones, total, dp);
    }
};