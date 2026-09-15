class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        for(int i=0;i<9;i++){
            unordered_set<char> seen;

            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;

                if(seen.count(board[i][j])) return false;

                seen.insert(board[i][j]);
            }
        }

        //check cols
        for(int j=0;j<9;j++){
            unordered_set<char> seen;

            for(int i=0;i<9;i++){
                if(board[i][j] == '.') continue;

                if(seen.count(board[i][j])) return false;

                seen.insert(board[i][j]);
            }
        }

        //check 3x3 boxes
        for(int row=0;row<9;row += 3){
            for(int col =0;col<9;col += 3){
                unordered_set<char> seen;

                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){

                        if (board[i][j] == '.') continue;

                        if (seen.count(board[i][j]))
                            return false;

                        seen.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};