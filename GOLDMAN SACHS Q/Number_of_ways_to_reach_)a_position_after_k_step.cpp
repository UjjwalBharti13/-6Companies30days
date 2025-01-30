class Solution {
public:
  // Approach
  /*
      This is simply Dp problem 
        we think like either we can go back of either we can go front 
           let start pos = dest =y and k is step
              then if we go back then return x-1 and reduce one value from k
               agsin if  we go  front then we return x+1 and again decrese one value from k

                 base case we think if x==y and k became 0
                    then we got a valifd path 
                     if x==y and k not become zero then it is invalid path then we return 0
  */
    #define ll long long int 
    ll mod = 1e9+7;
      
    ll dp[4001][1001];
      
    ll helper(ll currentPos, ll target, ll k){
           
           // base case 
           if(k==0 and currentPos==target) return 1;
           if(k==0) return 0;
           
            if(dp[currentPos+1000][k]!=-1) return dp[currentPos+1000][k];

           ll moveForward = helper(currentPos+1, target,k-1);
           ll moveBack  = helper(currentPos-1, target, k-1);
                 
                 return dp[currentPos+1000][k]=(moveForward+moveBack)%mod;
    }
    ll numberOfWays(ll startPos, ll endPos, ll k) {
           
              memset(dp,-1,sizeof dp);
            return helper(startPos,endPos,k);
    }
};
