class Solution {
public:
     int x_dir[4] = {1,-1,0,0};
     int y_dir[4] = {0,0,1,-1};

     void dfs(vector<vector<char>>& board, int i, int j){
         int n = board.size();
          int m = board[0].size();

          // base case

          if(i<0 or j<0 or i>=n or j>=m or board[i][j]!='X') return;
              
              board[i][j]='2';

              for(int d=0;d<4;d++){
                 dfs(board, i+x_dir[d], j+y_dir[d]);
              }
     } 
    int countBattleships(vector<vector<char>>& board) {
           int n= board.size();
           int m= board[0].size();
           int count=0;

           for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(board[i][j]=='X'){
                     dfs(board,i,j);
                     count++;
                 }
             }
           }
              return count;

    }
};
