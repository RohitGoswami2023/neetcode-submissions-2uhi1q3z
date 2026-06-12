class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0 ;
        for( int s : nums) sum += s;
        if( sum % k != 0) return false;
        int target = sum / k ;
        int n = nums.size();
        int total = 1 << n ;
        vector<int>dp(total , -1);
        dp[0] = 0;
        for( int i = 0 ; i < total ; i++){
            if(dp[i] == -1) continue;
        for( int j = 0 ; j < n ; j++){
            if( !( i & (1<< j))){
                if (dp[i] + nums[j] <= target){
                    int next = i |(1<< j);
                    dp[next] = (dp[i] + nums[j]) % target;
                }
            } 
        }
        }
        return dp[total - 1] == 0;
    }
};