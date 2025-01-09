class Solution {
public:
 bool isValid(vector<vector<char>>& board, int i, int j, char ch, int row, int col){
         // check for row
         for(int k=0;k<col;k++){
             if(k!=j and board[i][k]==ch) return false;

         }
         // check for column
         for(int k=0;k<row;k++){
             if(k!=i and board[k][j]==ch) return false;
         }
         // check each block
         int new_row=3*(i/3);
         int new_col=3*(j/3);
           for(int k=new_row;k<new_row+3;k++){
             for(int l=new_col;l<new_col+3;l++){
                 if(k!=i and l!=j and board[k][l]==ch) return false;
             }
           }
            return true;
 }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
            // traverse whole board;
             for(int i=0;i<row;i++){
                 for(int j=0;j<col;j++){
                     if(board[i][j]!='.'){
                         if(!isValid(board,i,j,board[i][j],row,col)){
                               return false;
                         }
                     }
                 }
             }
              return true;
    }
};
