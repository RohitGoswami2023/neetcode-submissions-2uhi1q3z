class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int Zerosum = 0;
        int windowSum = 0 ,maxWindowSum = 0 ;
        for( int i = 0 ; i < n ; i++){
            if(grumpy[i] == 0) Zerosum+=customers[i];
            if( i < minutes){
                windowSum += (grumpy[i] == 1 ? customers[i] : 0);
            }
            else {
                 windowSum += (grumpy[i] == 1 ? customers[i] : 0);
                 windowSum -= (grumpy[i - minutes] == 1 ? customers[i- minutes] : 0);

            }
            maxWindowSum = max(windowSum , maxWindowSum);
        }
        return (Zerosum + maxWindowSum);
    }
};