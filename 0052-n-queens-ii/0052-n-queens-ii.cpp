class Solution {
public:
    bool issafe(const vector<string>& board, int col, int row, int n) {
        for (int prevcol = 0; prevcol < col; prevcol++) {
            int prevrow = -1;
            for (int r = 0; r < n; r++) {
                if (board[r][prevcol] == 'Q') {
                    prevrow = r;
                    break;
                }
            }
            if (abs(prevrow - row) == abs(prevcol - col))
                return false;
        }
        return true;
    }

    void solve(int col,int n,vector<string>& board, vector<bool>& rowused,int& cnt){
        if(col==n){
            cnt++;
            return;
        }

        for(int row=0;row<n;row++){

            if(rowused[row] || !issafe(board,col,row,n)) continue;//invalid position

            //choose
            board[row][col] = 'Q';
            rowused[row] = true;

            solve(col+1,n,board,rowused,cnt); //explore

            //unchoose
            board[row][col] = '.';
            rowused[row] = false;

        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<bool> rowused(n,false);

        int cnt = 0;

        solve(0,n,board,rowused,cnt);

        return cnt;
    }
};