class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    int ans = 0;
    unordered_map<char,bool> mp;
    for( char ch : allowed) mp[ch] = true;
    for( string &word : words){
    bool ok = true;
    for(char ch : word){
        if(!mp[ch]){
            ok = false;
            break;
        }
    }
    if(ok) ans++;
    }
    
    return ans;
    }
};