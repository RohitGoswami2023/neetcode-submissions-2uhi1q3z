class Solution {
public:
vector<vector<int>>res;
void helper( vector<int>&arr  , int target  , int i , int j){
    while( i  < j){
        if(arr[i] + arr[j] > target ) j--;
        else if( arr[i] + arr[j] < target ) i++;
        else {
            while( i < j && arr[i] == arr[i + 1]) i++;
            while( i < j && arr[j] == arr[j - 1]) j--;
            res.push_back({-target , arr[i] , arr[j]});
            i++; 
            j--;
        }
    }
}
public:
 
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        if( n < 3) return {};
        for( int i  = 0 ; i< n ; i++ ){
            if ( i > 0 && nums[i] == nums[i  - 1]) continue;
            int n1 = nums[i];
            int target = - n1 ;
            helper( nums , target , i +1 , n - 1);
           
        }
         return res;
    }
};
