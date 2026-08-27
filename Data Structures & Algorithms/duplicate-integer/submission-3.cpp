class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for( int n : nums) mp[n]++;
        for( int i = 0 ; i < nums.size() ;i++){
            int a = nums[i];
            if( mp[a] >1 ) return true;
            
        }
       return false; 
    }

};