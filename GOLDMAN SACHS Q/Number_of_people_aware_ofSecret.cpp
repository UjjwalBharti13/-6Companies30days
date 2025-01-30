class Solution {
public:
// Approach
 /*
         for solving this 
         we make ans vector that store all the value on the ntj day hoe many person know the secret

           we store all the value on the index that hoe many person lnow the secret
           
              at the end on the nth day we return the sum of all person we didnt forget the secret   
 */
     int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
           
              vector<int> secret(2005,0);
                   
                   secret[1]=1;
                    
                    for(int i=1;i<=n;i++){
                         for(int idx=i+delay; idx<i+forget; idx++){
                              secret[idx] = (secret[idx]+secret[i])%mod;
                         }
                           
                    }
                       int ans=0;

                       // return the sum on nth day person who n]knows the secret

                       for(int i=max(1,n-forget+1);i<=n;i++){
                            ans  = (ans + secret[i])%mod;
                       }
                       return ans;
    }
};
