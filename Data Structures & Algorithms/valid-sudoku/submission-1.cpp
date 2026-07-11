class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char>x;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(x.count(board[i][j]))return false;
                x.insert(board[i][j]);
            }
            
        }
        for(int i=0;i<9;i++){
            unordered_set<char>x;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(x.count(board[j][i]))return false;
                x.insert(board[j][i]);
            }
        }
        for(int k=0;k<9;k++){
            unordered_set<char>x;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int row=(k/3)*3+i;
                    int col=(k%3)*3+j;
                    if(board[row][col]=='.')continue;
                    if(x.count(board[row][col]))return false;
                    x.insert(board[row][col]);
                }
                
            }
        }
        return true;
    }
};
