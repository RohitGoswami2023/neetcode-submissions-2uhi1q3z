class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     sort(nums.begin() , nums.end());
     set<vector<int>>st;
     int n = nums.size();
     int total = 1 << n ;
     for( int i = 0 ; i < total ; i++){
        vector<int>current;
        for(int j = 0 ; j < n ; j++){
            if( i & (1<< j)){
                current.push_back(nums[j]);
            }
        }
        st.insert(current);
     }
    return vector<vector<int>>(st.begin() , st.end());
    }
};
