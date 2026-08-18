class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0 , maxfreq = 0 , i = 0 , j =0 ;
        unordered_map<char,int>mp;
        while(j < s .size()){
            mp[s[j]]++;
            maxfreq = max(maxfreq , mp[s[j]]);
            if( (j - i +1)  - maxfreq  > k){
                mp[s[i]]--;
                i++;
            }
            res= max(res, j-i+1);
            j++;
        }
        return res;
    }
};
