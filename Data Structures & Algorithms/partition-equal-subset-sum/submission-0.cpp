class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums)
            sum += num;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(target + 1, -1));

        return targetSumSubset(nums, 0, 0, target, dp);
    }

private:
    bool targetSumSubset(vector<int>& nums,
                         int index,
                         int currSum,
                         int target,
                         vector<vector<int>>& dp) {

        if (currSum == target)
            return true;

        if (index == nums.size() || currSum > target)
            return false;

        if (dp[index][currSum] != -1)
            return dp[index][currSum];

        bool take = targetSumSubset(
            nums,
            index + 1,
            currSum + nums[index],
            target,
            dp
        );

        bool skip = targetSumSubset(
            nums,
            index + 1,
            currSum,
            target,
            dp
        );

        return dp[index][currSum] = take || skip;
    }
};