class Solution {
int kadane_Max(vector<int>& nums){
    int currSum = nums[0];
    int maxSum = nums[0];
    for ( int i = 1  ; i< nums.size() ;i++){
        currSum = max(nums[i] , currSum + nums[i]);
        maxSum = max(currSum , maxSum);
    }
    return maxSum ;
}
int kadane_Min(vector<int>& nums){
    int currSum = nums[0];
    int minSum = nums[0];
    for ( int i = 1  ; i< nums.size() ;i++){
        currSum = min(nums[i] , currSum + nums[i]);
        minSum = min(currSum , minSum);
    }
    return minSum ;
}
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum = 0 ;
        for ( auto num : nums) sum+=num;
        int minSum = kadane_Min(nums);
        int maxSum = kadane_Max(nums);
        int ans = sum - minSum;
        if(maxSum > 0) return max(maxSum , ans);
        return maxSum;
    }
};