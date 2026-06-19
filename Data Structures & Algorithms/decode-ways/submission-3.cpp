class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.length() , -1);
        return help(s , 0 , dp);
    }
private :
    int help( string s , int idx , vector<int>&dp){
        int l = s.length();
        if( idx == l  ) return 1 ;
        if( s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int ways1 = help(s, idx +1 , dp);
        int ways2 = 0;
        if( idx + 1  < l ){
            string temp = s.substr(idx , 2);
            if(stoi(temp) <= 26) 
            ways2 = help(s, idx+2 , dp);
        }
        return dp[idx] = ways1 + ways2;
    }
};
