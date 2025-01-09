class Solution {
  public:
      char arr[9] = {'!','#','$','%','&','*','?','@','^'};
   
    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
         int idx=0;
         for(int i=0;i<9;i++){
              for(int j=0;j<n;j++){
                   if(arr[i]==bolts[j]){
                        swap(bolts[j],bolts[idx]);
                        nuts[idx]=bolts[idx];
                           idx++;
                          
                   }
              }
         }
       
    }
};
