class Solution {
public:

    vector<vector<int>> table;
      int wave;
    Solution(int m, int n) {
           wave =1;
             
             table.resize(m,vector<int>(n,0));


    }
    
    vector<int> flip() {
        
        int y = rand()% table.size();
        int x = rand()% table[0].size();

           while(table[y][x] ==wave){
             if( ++x == table[0].size()){
                   x = 0;
                   y++;
             }
             if(y==table.size()) y=0;
           }
             table[y][x] = wave;
               return{y,x};
    }
    
    void reset() {
        wave++;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
