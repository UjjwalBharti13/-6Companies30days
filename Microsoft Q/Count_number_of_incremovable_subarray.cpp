class Solution {
public:
  bool isSorted(vector<int>& nums, int s, int e){
       for(int i=s;i<e;i++){
         if(nums[i]>=nums[i+1]){
             return false;
         }
          
       }
          return true;
  }
    int incremovableSubarrayCount(vector<int>& nums) {
          int ans=0;
            int n = nums.size();
              //  check each subarray weather it is sorted or not if yes then check it is in within bound if yes then  increament in answer 

             for(int i=0;i<n;i++){
                 for(int j=i;j<n;j++){
                     if(i==0 and j==n-1) continue;
                     if(isSorted(nums,0,i-1) and isSorted(nums,j+1,n-1)){
                         if(i-1>=0 and j+1<n and nums[i-1]>=nums[j+1]) continue;
                          ans++;
                     }
                      
                 }
             } 
              // since we are checking each sub array so it meand we have to add +1 at the end of the answer so return answer+1
              return ans+1;

    }
};
