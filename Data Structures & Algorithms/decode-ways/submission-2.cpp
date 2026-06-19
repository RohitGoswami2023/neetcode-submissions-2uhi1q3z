class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.length() , -1);
        return decodeWays(s , 0 , dp);
    }
private:
    int decodeWays(string s , int index , vector<int>&dp){
        int l = s.length();
        if(index == l ) return 1 ;
        if(s[index] == '0' ) return 0;
        if( dp[index] != -1) return dp[index];
        int ways1 = decodeWays(s,index+1 , dp);
        int ways2 = 0 ;
        if( index +1 < l){
            string temp = s.substr(index , 2);
            if(stoi(temp) <= 26){
                ways2 = decodeWays(s, index +2 , dp);
            }
            
        }
        return dp[index] = ways1 + ways2;
    }
};