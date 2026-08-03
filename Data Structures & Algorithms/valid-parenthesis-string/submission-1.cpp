class Solution {
public:
    bool checkValidString(string s) {
        stack <int>open ;
        stack <int> ast ;
        for ( int i = 0 ;  i < s.length() ; i++){
            if ( s[i] == '(') open.push(i);
            else if ( s[i] == '*') ast.push(i);
            else{
                if(!open.empty()) open.pop();
                else if ( !ast.empty()) ast.pop();
                else return false;
            }

        }
        while( !open.empty() && !ast.empty()){
            if(open.top() > ast.top()) return false;
            open.pop();
            ast.pop();
        }
        return open.empty();
    }
};
