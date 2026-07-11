class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      map<int , int > mp;
      for ( int num : nums) mp[num]++;
      int i = 0 ;
      for ( auto x : mp){
        nums[i] = x.first;
        i++;
      }  
      return i;
    }
};