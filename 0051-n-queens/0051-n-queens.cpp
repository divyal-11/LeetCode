class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> rowUsed(n, false);
        solve(0, n, board, rowUsed, result);
        return result;
    }
private:
    void solve(int col, int n, vector<string>& board, vector<bool>& rowUsed, vector<vector<string>>& result) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (rowUsed[row] || !isSafe(board, col, row, n)) continue;

            board[row][col] = 'Q';
            rowUsed[row] = true;

            solve(col + 1, n, board, rowUsed, result);

            board[row][col] = '.';
            rowUsed[row] = false;
        }
    }

    bool isSafe(const vector<string>& board, int col, int row, int n) {
        for (int prevCol = 0; prevCol < col; ++prevCol) {
            int prevRow = -1;
            for (int r = 0; r < n; ++r) {
                if (board[r][prevCol] == 'Q') {
                    prevRow = r;
                    break;
                }
            }

            // Check diagonal
            if (abs(prevRow - row) == abs(prevCol - col))
                return false;
        }
        return true;
    }
};