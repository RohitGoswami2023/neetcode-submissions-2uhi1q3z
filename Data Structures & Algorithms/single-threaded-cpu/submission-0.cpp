

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // FIX 1: Use a standard nested vector declaration
        vector<vector<int>> sortedTask;
        for(int i = 0; i < n; i++){
            int start_time = tasks[i][0];
            int end_time = tasks[i][1]; // FIX 2: Fixed typo from task -> tasks
            sortedTask.push_back({start_time, end_time, i});
        }
        
        sort(sortedTask.begin(), sortedTask.end());
        
        // FIX 3: Added the missing Priority Queue declaration
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> result;
        long long curr_time = 0; // Use long long to avoid any potential clock overflow
        int idx = 0;
        
        while(!pq.empty() || idx < n){
            if(pq.empty() && curr_time < sortedTask[idx][0]){
                curr_time = sortedTask[idx][0];
            }
            
            while(idx < n && sortedTask[idx][0] <= curr_time){
                pq.push({sortedTask[idx][1], sortedTask[idx][2]}); // FIX 3: Added missing semicolon
                idx++;
            }
            
            pair<int, int> curr_task = pq.top();
            pq.pop();
            
            curr_time += curr_task.first; // FIX 2: Fixed typo from firs -> first
            result.push_back(curr_task.second); // FIX 4: Push the original index, not the clock time!
        }
        
        return result;
    }
};