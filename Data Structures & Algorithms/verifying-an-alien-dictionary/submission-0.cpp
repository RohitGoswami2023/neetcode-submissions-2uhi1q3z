class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char , int > mp;
        for ( int i  = 0 ;i < order.size() ;i++)
        mp[order[i]] =  i ;

        for ( int i = 0 ;  i< words.size() -1 ; i++){
         string &a = words[i];
         string &b = words[i + 1];
         int len = min( a.size() , b.size());
         bool found = false ;
         for ( int j = 0 ; j < len ; j++){
            if( a[j] == b[j]) continue;
            if ( mp[a[j]] > mp[b[j]]) return false ;
            found = true;
            break;
         }
         if ( !found && a.size() > b.size()) return false ;
         
        }
      return true;
    }
};