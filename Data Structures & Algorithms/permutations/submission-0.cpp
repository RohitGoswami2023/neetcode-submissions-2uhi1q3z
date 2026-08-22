class Solution {
private:
    void solve ( vector<int>&curr , vector<bool>& visited , vector<int> & nums  ){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for ( int i = 0 ; i< nums.size() ; i++){
            if( visited[i]) continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            solve(curr ,visited , nums);
            curr.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    vector<int>curr ; 
    vector<bool>visited( n , false );
    solve( curr  , visited  , nums );
    return res;
    }
};
