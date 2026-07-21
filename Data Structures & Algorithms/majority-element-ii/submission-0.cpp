class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int,int> mp;

        for (int num : nums)
            mp[num]++;

        for (auto x : mp) {
            if (x.second > n / 3)
                res.push_back(x.first);
        }

        return res;
    }
};