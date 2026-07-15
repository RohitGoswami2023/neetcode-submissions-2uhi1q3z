class Solution {
private:
    // Fixed: Changed bool to char to match the board type
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c) return;
        
        if (board[i][j] != 'O') return;
        
        board[i][j] = '#';
        
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

public:
    int r, c; 
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        r = board.size();
        c = board[0].size();
        
        for (int i = 0; i < r; i++) {
            dfs(board, i, 0);
            dfs(board, i, c - 1);
        }
        
        for (int j = 0; j < c; j++) {
            dfs(board, 0, j);
            dfs(board, r - 1, j);
        }
        
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};