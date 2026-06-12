class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        int duplicate = -1;
        int missing = -1;
        int n = nums.size();

        for(auto x : mp) {
            if(x.second == 2) {
                duplicate = x.first;
                break;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(mp.find(i) == mp.end()) {
                missing = i;
                break;
            }
        }

        return {duplicate, missing};
    }
};