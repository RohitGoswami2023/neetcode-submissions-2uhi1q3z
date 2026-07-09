

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        vector<vector<int>> sortedTask;
        for(int i = 0; i < n; i++){
            int start_time = tasks[i][0];
            int end_time = tasks[i][1]; 
            sortedTask.push_back({start_time, end_time, i});
        }
        
        sort(sortedTask.begin(), sortedTask.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> result;
        long long curr_time = 0; 
        int idx = 0;
        
        while(!pq.empty() || idx < n){
            if(pq.empty() && curr_time < sortedTask[idx][0]){
                curr_time = sortedTask[idx][0];
            }
            
            while(idx < n && sortedTask[idx][0] <= curr_time){
                pq.push({sortedTask[idx][1], sortedTask[idx][2]}); 
                idx++;
            }
            
            pair<int, int> curr_task = pq.top();
            pq.pop();
            
            curr_time += curr_task.first; 
            result.push_back(curr_task.second); 
        }
        
        return result;
    }
};