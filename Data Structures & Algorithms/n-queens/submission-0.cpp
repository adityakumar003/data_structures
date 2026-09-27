class Solution {
public:
    bool safe(int row, int col, vector<string>& board, int n) {
        // left
        for (int j = 0; j < col; j++)
            if (board[row][j] == 'Q') return false;

        // upper-left
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // lower-left
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(int col, vector<string>& board,
               vector<vector<string>>& ans, int n) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (safe(row, col, board, n)) {
                board[row][col] = 'Q';

                solve(col + 1, board, ans, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);

        return ans;
    }
};