class Solution {
public:
 // Approach 
 /* 
    This is simply a back tracking problem 
       we can use it recusrsively with the taking case handle of k and i  
         here i can be goes upti 10 onlt 
           and even we we take an elemnet thne we reduce value 1 from k  
                
                when we skipping then push the val and then pick the element and after that do backtrack
 
 */
   
    void helper(int i, int t, vector<int>& sol, vector<vector<int>>& ans,int k){
           
             if(t==0 and k==0){
                 ans.push_back(sol);
                   return;
             }
               if(k<0 or t<0) {
                 return ;
               }

               if(i==10) return;

               // skip yhe element
                 helper(i+1,t,sol,ans,k);

                 // pick the element
                   sol.push_back(i);
                 helper(i+1,t-i,sol,ans,k-1);
                 // backtrack karna hia
                    
                     sol.pop_back();

    }

    vector<vector<int>> combinationSum3(int k, int n) {
           
             vector<vector<int>> ans;
             vector<int> sol;
                helper(1,n,sol,ans,k);
                  return ans;

           
    }
};
