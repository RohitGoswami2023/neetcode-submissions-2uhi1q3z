class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int totalJump = 0 ;
        int dest = nums.size() - 1;
        int cover = 0 ;
        int lastJump = 0 ; 
        for ( int i = 0 ; i< nums.size() ; i++){
        
            cover = max(cover , i + nums[i]);
            if(i == lastJump){
                lastJump = cover;
                totalJump += 1;

            
            if( cover >= dest){
                return totalJump;
            }
            }
        
     
        }
        if (nums.size() <= 1) return 0;
    }
};
