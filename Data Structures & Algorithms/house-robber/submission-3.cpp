class Solution {
   public:
    int help( vector<int>&nums , int index , vector<int>&dp ){
        if(index >= nums.size() ) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + help(nums , index + 2 , dp);
        int notpick = 0 + help(nums , index + 1, dp);
        return dp[index] =  max(pick , notpick);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp( n + 1 , -1);

         return help(nums, 0 , dp);
         
        }
};
