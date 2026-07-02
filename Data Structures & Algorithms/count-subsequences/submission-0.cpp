class Solution {
private:
    int n , m  ;
    int slove(string  & s , string & t , int i , int j , vector<vector<int>>& dp){
        if( j ==  m  ) return 1 ;
        if ( i == n ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s[i] == t[j]) {
            dp[i][j] = slove(s , t , i +1 , j +1 , dp) + slove ( s , t , i+1 , j , dp);
        }
        else dp[i][j] = slove( s , t , i +1 , j , dp);
       return dp[i][j]; 
    }

public:
    int numDistinct(string s, string t) {
         n = s.length();
         m = t.length();
        vector<vector<int>>dp( n , vector<int>( m ,  - 1));
        return slove(s , t , 0 , 0  , dp);
    }
};
