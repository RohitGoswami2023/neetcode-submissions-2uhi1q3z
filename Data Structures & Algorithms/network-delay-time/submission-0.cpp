class Solution {
public:

    typedef pair<int,int> P;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> graph(n+1);

        for(auto &time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            graph[u].push_back({v,w});
        }

        vector<int> result(n+1, INT_MAX);

        result[k]=0;

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0,k});

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currTime = curr.first;
            int node = curr.second;

            if(currTime > result[node])
                continue;

            for(auto &neigh : graph[node])
            {
                int neighbor = neigh.first;
                int weight = neigh.second;

                if(result[neighbor] > currTime + weight)
                {
                    result[neighbor] = currTime + weight;

                    pq.push({result[neighbor],neighbor});
                }
            }
        }

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            if(result[i]==INT_MAX)
                return -1;

            ans=max(ans,result[i]);
        }

        return ans;
    }
};