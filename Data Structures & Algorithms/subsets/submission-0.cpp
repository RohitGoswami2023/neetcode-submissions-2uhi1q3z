class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>powerset;
        int total = 1 << n;
        for( int i = 0 ; i < total ; i++){
            vector<int>current;
            for( int j = 0 ; j< n ; j++){
                if((i & (1 << j  ) )!= 0) {
                    current.push_back(nums[j]);
                }
            }
         powerset.push_back(current);
        }
        return powerset;
    }
};
