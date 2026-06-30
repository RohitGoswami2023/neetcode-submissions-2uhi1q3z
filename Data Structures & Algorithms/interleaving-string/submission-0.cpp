class Solution {
private:
bool slove( string & s1 , string & s2 , string & s3 , int i , int j , vector<vector<int>>&dp)
{
 if(i == s1.length() && j == s2.length()) return true;
 if( dp[i][j]  != -1) return dp[i][j];
 bool choice1 = false , choice2 = false;
 if( i <s1.length() && s1[i] == s3[i+j]){
    choice1  =slove(s1 , s2 , s3 , i+1 , j , dp);
 }
 if(j < s2.length() && s2[j] == s3[i+j]){
    choice2 = slove(s1 , s2 , s3, i , j +1 , dp);
 }
 return dp[i][j] = (choice1 || choice2);
}

public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length() ;
        int b = s2.length() ;
        int c = s3.length() ;
        if( a  + b != c) return false;
        vector<vector<int>>dp(101 , vector<int>(101 , -1));
        return slove(s1 , s2 , s3 , 0 , 0 , dp );

    }
};
