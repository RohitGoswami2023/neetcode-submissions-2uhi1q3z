class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int left = 0 ,  res = 0 , window =0 ;
    for(int right = 0 ; right < nums.size(); right++) {
        window += nums[right];
        while(window + k < right -left + 1){
                window -= nums[left++];
        }
         res = max(res ,( right -left +1));

    }   
    return res;
    }
};