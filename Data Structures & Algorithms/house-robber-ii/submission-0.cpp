class Solution {
private:
    int helper(vector<int>& nums, int start, int end){
        int take_profit = 0; 
        int skip_profit = 0; 
        
        for(int i = start; i <= end; i++) {
            int current_house_cash = nums[i];
            
            int old_take = take_profit;
            int old_skip = skip_profit;
            take_profit = old_skip + current_house_cash;
            skip_profit = max(old_take, old_skip);
        }
        
        return max(take_profit, skip_profit);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0]; 
        
        int first = helper(nums, 0, n - 2);
        int last = helper(nums, 1, n - 1);
        
        return max(first, last); 
    }
};