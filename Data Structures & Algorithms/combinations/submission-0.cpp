class Solution {
    vector<vector<int>> res ;
    
    void solve( int start , int n , int k , vector<int> & curr){
        if ( k == 0){
            res.push_back(curr);
            return ;
        }
        if ( start  > n ) return ;
        curr.push_back(start);
        solve ( start + 1 ,  n ,k -1 , curr);
        curr.pop_back();
        solve( start + 1 , n , k , curr );
    }

public:
    vector<vector<int>> combine(int n, int k) {
    vector<int> curr ;
    solve(1  , n , k , curr);
    return res;
    }
};