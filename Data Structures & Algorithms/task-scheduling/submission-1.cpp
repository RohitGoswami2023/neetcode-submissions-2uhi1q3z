class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        for (int task : tasks) {
            mp[task]++;
        }

        for (auto p : mp) {
            pq.push(p.second);
        }
        int totalTime = 0 ;

        while (!pq.empty()) {
            vector<int> temp;
            int cycleLength = n +1 ;
            int taskComplete = 0 ; 

            for (int i = 1; i <= cycleLength ; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                    taskComplete++;
                }
            }
            for(int freq : temp) {
                if (freq > 0) {
                    pq.push(freq);
                }
            }
            totalTime += pq.empty() ? taskComplete : cycleLength;
        }
        return totalTime;
    }
};
