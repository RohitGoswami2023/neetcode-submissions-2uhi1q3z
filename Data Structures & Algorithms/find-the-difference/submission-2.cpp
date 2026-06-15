class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char , int>mp;
       
       for( char c : s) mp[c]++;
       for( char c : t) mp[c]++;
       for( auto y : mp){
        if(y.second %2 != 0 ) return y.first;
       }
       return -1;
    }
};