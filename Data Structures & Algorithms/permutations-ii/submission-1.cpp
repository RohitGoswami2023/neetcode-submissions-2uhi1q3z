class Solution {
private:
    void solve( vector<int> & nums , vector<int>& curr , vector<bool>&visited ){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }
        for ( int i = 0 ; i< nums.size() ; i++){
            if(visited[i]) continue;
            if( i > 0 && nums[i] == nums[i  - 1] && !visited[i - 1]) continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            solve(nums, curr  , visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>>result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        vector<bool>visited(n , false);
        sort(nums.begin() , nums.end());
        solve(nums, curr , visited);
        return result;
    }
};