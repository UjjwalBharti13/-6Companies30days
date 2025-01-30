class Solution {
public:
   // Approah 
   /*
        for Solving this we made set 
        and store every distict subaraay in set
           if any element is divisible by p then increment cout 
           if smaller than we put in set and in temp vector 
   */
    int countDistinct(vector<int>& nums, int k, int p) {
            int n =  nums.size();
                 
                set<vector<int>> st;
                 
                   for(int i=0;i<n;i++){
                      
                      int count=0;
                      vector<int> temp;
                      for(int j=i;j<n;j++){
                         if(nums[j]%p==0) count++;
                          if(count>k){
                             break;
                         }
                         else {
                             temp.push_back(nums[j]);
                                st.insert(temp);
                         }
                      }
                   }
                   return st.size();
    }
};
