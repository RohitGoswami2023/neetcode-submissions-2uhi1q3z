#include<cstring>

class Solution {
private :
int mem[3001];
bool dfs(string & s , int start , unordered_set<string>& dict){
    if(start  >= s.length()) return true;
    if( mem[start] != - 1) return mem[start];
    for( int i = start  ; i< s.length() ; i++){
        string current_word = s.substr(start , i -start +1);
        if(dict.count(current_word)){
            if(dfs(s , i +1  , dict)) {
                return mem[start] = true;
            }

        }
    }
    return mem[start] = false;
}

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(mem , -1 , sizeof(mem));
        unordered_set<string>word(wordDict.begin() , wordDict.end());
        return dfs(s , 0 , word);
    }
};
