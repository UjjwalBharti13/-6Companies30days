
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
     int findMax(vector<int>& arr, int l, int r){
            int mx = INT_MIN;
             for(int i=l;i<=r;i++){
                  mx = max(mx,arr[i]);
             }
              return mx;
              
     }
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
             int n = arr.size();
              vector<int> ans;
              int l=0;
               int r=k-1;
               int max_ele = INT_MIN;
               
               for(int i=0;i<k;i++){
                   max_ele=max(max_ele,arr[i]);
               }
                 ans.push_back(max_ele);
                   while(r<n-1){
                        if(arr[l]==max_ele)
                             max_ele=findMax(arr,l+1,r);
                             l++;
                             r++;
                              max_ele=max(max_ele,arr[r]);
                              ans.push_back(max_ele);
                        
                            
                   }
                    return ans;
                   
    }
};
