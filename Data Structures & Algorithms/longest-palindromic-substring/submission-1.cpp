class Solution {
private:
    string expand(string&  s , int left , int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left --, right++;
        }
        return s.substr(left +1 , right - left -1);
    }

public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string longest = "";
        for(int i = 0 ; i < s.length() ; i++){
            string oddPalindrome = expand(s , i , i );
            if(oddPalindrome.length() > longest.length())
                longest = oddPalindrome;
            string evenPalindrome = expand(s , i ,i +1);
                if( evenPalindrome.length() > longest.length())
                longest = evenPalindrome;
            

        }
        return longest;
    }
};
