class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int array[1001] ={ 0};
        for ( auto &trip : trips){
            int pass = trip[0];
            int start = trip[1];
            int end = trip[2];
            array[start] += pass;
            array[end] -= pass;

        }
        int curr = 0 ;
        for( int i = 0 ; i <1001 ; i++){
            curr += array[i];
            if( curr > capacity) return false;
        }
        return true;
    }
};