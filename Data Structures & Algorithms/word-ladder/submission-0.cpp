class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string , int > freq;
        for ( int i = 0 ; i< n ; i++){
            freq[wordList[i]] = 1;
        }
        if( freq.find(beginWord) == freq.end()) freq[beginWord] = 1;
        if( freq .find(endWord) == freq.end()) return 0;
        queue<pair<string , int >> q;
        q.push({beginWord , 1});
        freq.erase(beginWord);
        while( !q.empty()){
            pair <string , int > p = q.front();
            q.pop();
            string s = p.first;
            int val =  p.second;
            if(s == endWord) return val;
            for ( int i = 0 ; i < s.length() ; i++){
                char c = s[i];
                for( int j = 97 ; j <= 122 ; j++  ){
                    if ( c == j) continue;
                    s[i]  = j ; 
                
                    if( freq.find(s) != freq.end()) {
                        q.push({s , val +1});
                        freq.erase(s);
                    }
                }
                s[i] = c;
            }
        }
    return 0;
    }
};
