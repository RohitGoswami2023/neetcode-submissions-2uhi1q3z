class Solution {
private:
    void fxn ( int index , int target  , vector<int>&nums , vector<vector<int>>&res,vector<int>&curr ){
        if( index == nums.size()){
            if ( target == 0){
                res.push_back(curr);
            }
            return ;
        } 
        if(nums[index] <= target ){
            curr.push_back( nums[index]);
            fxn(index , target - nums[index] , nums , res , curr);
            curr.pop_back();
        }
        fxn( index +1  , target , nums , res , curr);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>curr;
        fxn( 0 , target , nums , res ,curr); 
        return res;
    }
};
