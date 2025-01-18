class Solution {
public:
// Approach
     // first we caluculate number of iland through the help of dfs or bfs 
     //  afte that check if the number of i-land is lesst than 1 or greater than 1 so in this case we have to return 0  because they are already disconnected
       // if i-land is 1 then  we go to land wherr is 1 and make them 0 and afte rthat again count the number of i land if it is less than or greater than equal to 1 then we return 1 
       // after every iteration  if we coun't get iland value==1 thne at last we return 2 simple
     
      int x_dir[4]={1,-1,0,0};
      int y_dir[4]={0,0,1,-1};
      int bfs(vector<vector<int>>& grid, int n, int m, vector<vector<int>> vis){
             
              int island=0;
                queue<pair<int,int>> q;
                  
                   for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                         if(grid[i][j]==0 or vis[i][j]==1) continue;
                           island++;
                            
                            q.push({i,j});
                              vis[i][j]=1;

                              while(!q.empty()){
                                   auto curr = q.front();
                                   q.pop();

                                  for(int d=0;d<4;d++){
                                      int x = curr.first + x_dir[d];
                                      int y = curr.second + y_dir[d];

                                      if(x>=0 and x<n and y>=0 and y<m and grid[x][y]==1 and vis[x][y]==0){
                                         q.push({x,y});
                                           vis[x][y]=1;
                                      }
                              }
                              }
                     }
                   }
                    return island;
      }   
    int minDays(vector<vector<int>>& grid) {
          int n = grid.size();
           int m = grid[0].size();
            vector<vector<int>> vis(n,vector<int>(m,0));
               
               int ans = bfs(grid,n,m,vis);
                 if(ans<1 or ans>1) return 0;

                    for(int i=0;i<n;i++){
                         for(int j=0;j<m;j++){
                             if(grid[i][j]==1){
                                 grid[i][j]=0;
                                  ans= bfs(grid,n,m,vis);
                                  if(ans<1 or ans>1) return 1;
                                    grid[i][j]=1;
                             }
                         }
                    } 
                     return 2;

    }
};
