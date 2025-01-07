class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
         vector<int> dp1(n,1);
         vector<int> dp2(n,1);
             
             int ans=0; // store the maximumm number of mountain array
               
                // first we calculate length of increasing subsequence and store it in dp1
                for(int i=1;i<n;i++){
                     if(arr[i]>arr[i-1]){
                         dp1[i] = 1+dp1[i-1];
                     }
                }
                 // smae we calculate the lenght of decreasing subsequence and store it in dp2
                  
                  for(int i=n-2;i>=0;i--){
                     if(arr[i]>arr[i+1]){
                         dp2[i]=1+dp2[i+1];
                     }
                  }
                // now iterate each over ondex and find the length of kmountain array if lenght is greater than 1 tahn sum the both dp1 and dp2 otherwise return -1

                  for(int i=0;i<n;i++){
                     if(dp1[i]>1 and dp2[i]>1){
                         ans = max(dp1[i]+dp2[i]-1, ans);
                     }
                  }   
                    return ans;

               
    }
};
