class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxValue[3] = { 0 ,0 ,0};
        for ( auto &triplet : triplets ){
            if( triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                maxValue[0] = max( maxValue[0] , triplet[0]);
                maxValue[1] = max( maxValue[1] , triplet[1]);
                maxValue[2] = max( maxValue[2] , triplet[2]);
            }
        }
        return (maxValue[0] == target[0] && maxValue[1] == target[1] && maxValue[2] == target[2]);
    }
};
