class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;

        for (int x : nums)
            if (x > 0)
                mp[x]++;

        int ans = 1;

        while (mp.count(ans))
            ans++;

        return ans;
    }
};