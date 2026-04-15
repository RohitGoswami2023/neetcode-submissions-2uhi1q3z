class Solution {
public:
    int atmost(vector<int>&nums , int goal){
      int start = 0 , end = 0 , sum = 0  , n = nums.size() , count = 0;
      for(end = 0 ; end < n ; end++){
        sum += nums[end];
        while(start <= end  && sum > goal){
          sum-=nums[start];
          start++;
        }
        count += ( end - start )+1;
      }
      return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (atmost(nums,goal) - atmost(nums,goal-1));

    }
};