class Solution {
public:
    int maxArea(vector<int>& heights) {
        int water = 0 ;
        int i = 0 , j = heights.size() - 1 ;
        while ( i < j ){
            int w = j - i ;
            int h = min(heights[i] , heights[j]);
           int  area  = w * h ;
            water = max( water , area);
            if( heights[i] >heights[j] ) j--;
            else i++;
        }
    return water ;
    }
};
