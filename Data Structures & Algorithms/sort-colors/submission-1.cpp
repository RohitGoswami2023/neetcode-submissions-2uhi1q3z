class Solution {
public:
    void sortColors(vector<int>& nums) {
       priority_queue<int, vector<int> , greater<int>>pq;
       for( int num  : nums) pq.push(num);
       vector<int>res;
       while( !pq.empty()){
        int x = pq.top();
        pq.pop();
        res.push_back(x);
       } 
       
       for( int i = 0 ; i < nums.size() ; i++){
        nums[i] = res[i];
       }
    }
};