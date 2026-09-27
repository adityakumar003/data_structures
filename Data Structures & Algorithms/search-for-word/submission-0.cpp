class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (index == word.length()) return true;

        // Out of bounds or already visited or mismatch
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || board[i][j] != word[index]) return false;

        char temp = board[i][j]; // Store current char
        board[i][j] = '#';       // Mark visited

        // Explore 4 directions
        bool found = dfs(board, i + 1, j, word, index + 1) ||
                     dfs(board, i - 1, j, word, index + 1) ||
                     dfs(board, i, j + 1, word, index + 1) ||
                     dfs(board, i, j - 1, word, index + 1);

        board[i][j] = temp; // Backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
