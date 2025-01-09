class Solution {
public:
   unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
    int solve(int i, int& k, int isLastJump, int jump){
           
           if(i>k+1) return 0;
           //  we are not taking base case on when i reached to k because in Q statement saying we can perform operation again and again 
           if(dp.count(i) and dp[i].count(isLastJump) and dp[i][isLastJump].count(jump)){
                return dp[i][isLastJump][jump];
           }
             int ans=(i==k);

             ans +=solve(i+pow(2,jump),k,0,jump+1);
             if(i!=0 and not isLastJump){
                 ans+=solve(i-1,k,1,jump);
             }
             return dp[i][isLastJump][jump]=ans;

    }
    int waysToReachStair(int k) {
         return solve(1,k,0,0);
    }
};
