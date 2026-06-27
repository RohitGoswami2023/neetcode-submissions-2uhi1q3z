class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
       int n = stoneValue.size();
       vector<int>dp( n + 1 , 0);
       for( int i = n -1 ; i >= 0 ; i--){
        int ans = INT_MIN;
        int current = 0;
        for( int k =  0  ; k< 3 && i + k   < n ; k++){
            current += stoneValue[i +k ];
            int relative_Score  = current - dp[ i + k  +1];

        
        ans = max(ans , relative_Score);}
        dp[i] = ans;

       } 
        if (dp[0] >0 ) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};