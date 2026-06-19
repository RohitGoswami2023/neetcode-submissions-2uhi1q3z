class Solution {
private:
    int N;

public:
    int rob(vector<int>& nums) {

        this -> N = nums.size();
        vector<int> dp(this -> N + 1, -1);

        return house_robber(nums, 0, dp);
    }

private:
    int house_robber(vector<int>& nums, int index, vector<int>& dp) {

        if (index >= N)
            return 0;
        
        if (dp[index] != -1)
            return dp[index];

        int steal = nums[index] + house_robber(nums, index + 2, dp);
        int skip = 0 + house_robber(nums, index + 1, dp);

        return dp[index] = fmax(steal, skip);
    }
};
