class Solution {

public :
int n ,m ;
private :
int dfs ( vector<vector<int>>& grid  , int  i , int j , vector<vector<bool>> & visited){
    if(  i < 0 ||i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j] == true ) return 0;
    visited[i][j] = true ;
    return 1  + dfs( grid , i -1 , j , visited) 
              + dfs( grid , i +1 , j , visited)
              + dfs( grid , i , j + 1 , visited)
              + dfs( grid , i , j - 1 , visited);

}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0 ;
        vector<vector<bool>>visited( n , vector<bool> ( m , false));
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                
                if( grid[i][j] == 1 && !visited[i][j]){
                    int area = dfs( grid , i , j , visited);
                    maxArea = max( area , maxArea );
                }

            }
        }
        return maxArea;
    }
};
