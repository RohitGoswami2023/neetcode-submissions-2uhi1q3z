class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for (char x : s){
            if(isalnum(x)){
                temp += tolower(x);
            }
        }
        string rev = temp;
        reverse(rev.begin() , rev.end());
        return rev == temp; 
        
    }
};
