class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1, mp2;
        int i = 0, j = 0;

        for (int k = 0; k < s1.size(); k++) 
            mp1[s1[k]]++;

        int k = s1.size();

        while (j < s2.size()) {
            mp2[s2[j]]++;

            
            if (j - i + 1 > k) {
                mp2[s2[i]]--;
                if (mp2[s2[i]] == 0) {
                    mp2.erase(s2[i]);
                }
                i++;
            }

            
            if (j - i + 1 == k) {
                if (mp1 == mp2) {
                    return true;
                }
            }

            j++;
        }

        return false; 
    }
};