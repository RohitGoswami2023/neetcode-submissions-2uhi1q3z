class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char , int >mp;
       for ( auto x : s) mp[x]++;
       priority_queue<pair<int , char >> pq;
       for( auto p : mp){
        pq.push({p.second  , p.first});
       } 
       string result ="";
       pair<int , char > prev = { -1  ,'#'};
        while(!pq.empty()){
            pair<int  ,char > curr = pq.top();
            pq.pop();
            result += curr.second;
            curr.first--;
            if(prev.first > 0){
                pq.push(prev);
            }
            prev = curr;
        }
        if(result.length() == s.length()) return result;
        return "";
    }
};