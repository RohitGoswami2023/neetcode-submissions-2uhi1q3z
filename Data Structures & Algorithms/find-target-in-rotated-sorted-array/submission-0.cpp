class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int , int > mp;
        for ( int i = 0 ; i < nums.size() ; i++){
            mp.insert({nums[i] , i});
        }
        for ( auto x : mp){
            if (x.first == target ) return x.second;
        }
        return -1;
    }
};
