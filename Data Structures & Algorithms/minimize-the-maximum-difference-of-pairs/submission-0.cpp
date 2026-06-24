class Solution {
private:
bool possible(vector<int>&nums, int p , int minDiff){
    int count = 0 ;
    int n = nums.size();
    for( int i  =  1 ; i < n ; i++){
        if(nums[i] - nums[i -1] <= minDiff){
            count ++;
            i++;
        }
        if(count >= p) return true;
    }
    return (count >= p);
}

public:
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(), nums.end() );
       int n = nums.size();
       int ans = 0 ;
       int low = 0 ,high = nums[n -1] - nums[0];
       while( low <= high){
        int mid = low + (high - low ) /2;
            if (possible(nums , p , mid)) {
                ans = mid ;
                high = mid -1 ;
            }
            else low = mid + 1 ;
       } 
       return ans;
    }
};