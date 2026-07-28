class Solution {
    bool backtrack(vector<vector<char>>& board, string& word, int m, int n,
                   int row, int col, int index) {
        if (index == word.size())
            return true;
        if (row < 0 || row >= m || col < 0 || col >= n)
            return false;
        if (board[row][col] != word[index])
            return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool found = backtrack(board, word, m, n, row + 1, col, index + 1) ||
                     backtrack(board, word, m, n, row - 1, col, index + 1) ||
                     backtrack(board, word, m, n, row, col + 1, index + 1) ||
                     backtrack(board, word, m, n, row, col - 1, index + 1);
        board[row][col] = temp;
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, m, n, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};