class Solution {
    bool check(int row, int col, vector<int>& placed) {
        for(int nRow = 0; nRow < row; nRow++){
            int nCol = placed[nRow];
            if(col == nCol or abs(row-nRow)==abs(col-nCol)){
                return false;
            } 
        }
        return true;
    }
    void rec(int row, int n,vector<string>&board, vector<vector<string>>&boards,vector<int>& placed){
        if(row == n){
            boards.push_back(board);
            return;
        }

        for(int col = 0;col<n;col++){
            if(check(row,col,placed)){
                board[row][col] = 'Q';
                placed[row] = col;
                rec(row+1,n,board,boards,placed);
                placed[row] = -1;
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>boards;
        vector<string>board(n,string(n,'.'));
        vector<int> placed(n,-1);
        rec(0,n,board,boards,placed);
        return boards;
    }
};
