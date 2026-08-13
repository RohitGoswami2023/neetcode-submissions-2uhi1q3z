class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int count = 0 ;
        int l = 0 , h = people.size() - 1;
        while( l <= h){
            if( people[h] + people [l] <= limit){
                count++;
                l++ ,h--;
            }
            else {
                h--;
                count++;
            }
        } 
        return count;
    }
};