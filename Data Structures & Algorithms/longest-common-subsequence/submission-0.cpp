class Solution {
private:
int slove(int i , int j  , string &text1 , string &text2 , vector<vector<int>>&dp  ){
    if( i < 0 || j < 0) return 0;
    if(dp[i][j] != -1 ) return dp[i][j];
    if(text1[i] == text2[j]) {
      return   dp[i][j] = 1 + slove( i -1  , j-1 , text1 , text2 , dp);}

    return dp[i][j] = max(slove (i -1 , j , text1 , text2 , dp) ,slove( i , j-1 , text1 , text2 , dp) );

}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp( n , vector<int>( m ,-1));
        return slove ( n  - 1 , m -1  , text1 , text2 , dp);

    }
};
