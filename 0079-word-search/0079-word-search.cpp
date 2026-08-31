class Solution {
public:
    bool dfs(vector < vector<char >> &board, string& word, int row, int col,
             int idx) {

        if (idx == word.size())
            return true; // success

        // out of bounds
        if (row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size())
           return false;

        if (board[row][col] != word[idx])
            return false;

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = dfs(board, word, row + 1, col, idx + 1) ||
                     dfs(board, word, row - 1, col, idx + 1) ||
                     dfs(board, word, row, col + 1, idx + 1) ||
                     dfs(board, word, row, col - 1, idx + 1);

        board[row][col] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as a starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};