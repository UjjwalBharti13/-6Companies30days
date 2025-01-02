class Solution {
public:
    int dir_x[9]={-1,-1,-1,0,0,0,1,1,1};
    int dir_y[9]={-1,0,1,-1,0,1,-1,0,1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
          // we can solve this problem with the help of dfs
      // first we make vector and traverse through dfs
            int n = img.size();
             int m = img[0].size();
               vector<vector<int>> grid(n,vector<int>(m,0));
                
               for(int i=0;i<n;i++){
                 for(int j=0;j<m;j++){
                      int total_sum=0;
                      int count=0;

                        // Calculate the sum of the pixel values in the 3x3 neighborhood
                    for(int d=0;d<9;d++){
                         int next_i = i+dir_x[d];
                         int next_j = j+dir_y[d];

                         if(next_i>=0 and next_i<n and next_j>=0 and next_j<m){
                               total_sum += img[next_i][next_j];
                                 count+=1;
                         }
                    }
                        // Compute the average and store it in the result matrix
                        grid[i][j] = total_sum/count;
                 }
               } 
                  return grid;
    }
};
