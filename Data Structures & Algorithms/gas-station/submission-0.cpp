class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0, totalcost = 0;
        int currGas = 0, start = 0;
        for (int i = 0; i < n; i++) {
            totalgas += gas[i];
            totalcost += cost[i];
            currGas += (gas[i] - cost[i]);
            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        if (totalgas < totalcost) return -1;

        return start;
    }
};
