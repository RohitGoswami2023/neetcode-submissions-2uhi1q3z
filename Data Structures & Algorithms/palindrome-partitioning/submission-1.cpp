class Solution {
private :
bool isPal(string s){
     string s1 = s;
    reverse(s1.begin() , s1.end());
    if(s == s1) return true;
    return false;
}

void getAllpart( string s , vector<string>& partitions , vector<vector<string>>&ans){
    if( s.size() == 0) {
        ans.push_back(partitions);
        return ;
        }
    
    for( int i = 0  ; i <s.length() ; i++){
        string part = s.substr(0 , i+1) ;
        if(isPal(part)){
            partitions.push_back(part);
            getAllpart(s.substr(i+1) , partitions  , ans);
            partitions.pop_back();
        }

    }
}

public:
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        vector<vector<string>>ans;
         getAllpart(s , partitions , ans);
         return ans;
    }
};
