class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = nums.size() ;
        for( int i  = 0  ; i < nums.size() ; i++){
            xorr = xorr ^ nums[i]^ i ;
        }
        return xorr;
    }
};
