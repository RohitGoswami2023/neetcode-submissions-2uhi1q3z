class Solution {
private:
bool isPossible(vector<int> &arr , int k , int max_Sum ){
    int subarray = 1 ;
    int current = 0;
    for( int num : arr ){
        if(num > max_Sum ) return false;
        if(current + num <= max_Sum){
            current += num;
        }
        else{
            subarray++;
            current = num;
        }
    }
    return subarray <= k;
}

public:
    int splitArray(vector<int>& nums, int k) {
       int maxElement = *max_element(nums.begin() , nums.end());
       int sum = 0 ;
       for( int num : nums) sum+=num;
       int high = sum;
       int low = maxElement ;
       int ans = high;
       while( low <= high){
        int mid = low + ( high - low )/2;
        if(isPossible(nums , k , mid)){
            ans = mid ;
            high = mid -1 ;
        }
        else low = mid + 1;
       }
       return ans;
    }
};