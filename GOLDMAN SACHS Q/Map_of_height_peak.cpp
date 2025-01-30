class Solution {
public:
     // Approach  
     /*
          for solving this problem we have to apply muiltisource BFS

              first we marlk all the value of water to zero 
               then apply multisource BFS from all 0 value
                  
                  if value if curr grid[i][j] is not visited then add +1 to that value
                      and last return vector
      
      
     */ 


           int x_dir[4]={1,-1,0,0};
           int y_dir[4]={0,0,1,-1};
              
                

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
                  
                    int n = isWater.size();
                    int m  = isWater[0].size();
                      
                      vector<vector<int>> ans(n,vector<int>(m,-1));
                        
                        queue<pair<int,int>> q;
                    // assign all the water vallue to 0  

                    for(int i=0;i<n;i++){
                         for(int j=0;j<m;j++){
                             if(isWater[i][j]==1){
                                   ans[i][j]=0;
                                   q.push({i,j});
                             }
                        }
                    }

                    // Apply MultiSource BFS

                    while(!q.empty()){
                          int sz = q.size();

                          while(sz--){
                              
                               auto curr = q.front();
                               q.pop();
                                 
                                 int i = curr.first;
                                 int j = curr.second;

                                 for(int d=0;d<4;d++){
                                     
                                     int new_i = i+ x_dir[d];
                                     int new_j = j+ y_dir[d];

                                    if(new_i>=0 and new_i<n and new_j>=0 and new_j<m and ans[new_i][new_j]==-1){
                                           ans[new_i][new_j] = ans[i][j]+1;
                                           q.push({new_i,new_j});
                                    } 
                                 }
                          }
                    }
                     return ans;

    }
};
