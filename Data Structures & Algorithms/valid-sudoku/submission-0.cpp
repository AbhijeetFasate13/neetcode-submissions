class Solution {
    bool checkLine(int lineNum, bool isCol, vector<vector<char>>& board){
        unordered_map<char,int>mp;
        for(int i=0;i<9;i++){
            char c = isCol?board[i][lineNum]:board[lineNum][i];
            if(c=='.')continue;
            if(mp.count(c))return false;
            mp[c]++;
        }
        return true;
    }
    bool checkSub(int row, int col, vector<vector<char>>& board){
        unordered_map<char,int>mp;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                char c = board[i][j];
                if(c=='.')continue;
                if(mp.count(c))return false;
                mp[c]++;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int lineNum = 0;lineNum < 9;lineNum++){
            if(!checkLine(lineNum,false,board) or !checkLine(lineNum,true,board)){
                return false;
            }
        }
        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){
                if(!checkSub(row,col,board)){
                    return false;
                }
            }
        }
        return true;
    }
};
