class Solution {
public:

    bool issafe(vector<vector<char>>& board,int row,int col,char ch){
        //check row
        for(int j=0;j<9;j++){
            if(board[row][j]==ch) return false;
        }

        //check col
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
        }

        //check 3x3 box
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;

        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==ch)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(board[row][col]== '.'){
                    //try 1 to 9
                    for(char ch = '1';ch<='9';ch++){
                        if(issafe(board,row,col,ch)){

                            //choose
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};