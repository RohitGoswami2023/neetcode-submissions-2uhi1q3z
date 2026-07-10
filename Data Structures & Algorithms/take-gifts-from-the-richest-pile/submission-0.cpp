class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int x : gifts)
            pq.push(x);

        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.push((int)sqrt(x));
        }

        long long sum = 0;

        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};