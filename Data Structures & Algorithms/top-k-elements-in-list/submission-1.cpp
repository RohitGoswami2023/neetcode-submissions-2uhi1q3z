class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int , int > mp;
       for ( int num : nums) 
            mp[num]++;
        priority_queue<pair<int , int >> pq;
        for ( auto x : mp){
            pq.push({x.second , x .first });
        }
        vector<int>res;
        while( k--){
            pair<int , int > p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
    return res;
   }
};
